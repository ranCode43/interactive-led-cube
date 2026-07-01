#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

#include "wifi_canvas.h"
#include "led_effects.h"
#include "config.h"

// ----------------------------------------
// Access point settings
// ----------------------------------------
// Change these if you want a different name/password for the demo.
static const char *AP_SSID = "LED-Cube-Canvas";
static const char *AP_PASSWORD = "drawmecube";

static WebServer server(80);

// 8x8 canvas buffer (one value per grid cell), mirrored onto every face.
static const int GRID_SIZE = 8; // matches LEDS_PER_MATRIX (8x8)
static CRGB canvas[GRID_SIZE * GRID_SIZE];

static bool serverStarted = false;

// ----------------------------------------
// Web page served to visitors' phones
// ----------------------------------------
static const char INDEX_HTML[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>LED Cube - Live Canvas</title>
  <style>
    body { font-family: sans-serif; text-align: center; background: #111; color: #eee; }
    #grid { display: grid; grid-template-columns: repeat(8, 36px); grid-gap: 3px; justify-content: center; margin: 16px auto; }
    .cell { width: 36px; height: 36px; background: #222; border-radius: 4px; }
    #color { width: 60px; height: 40px; border: none; }
    button { padding: 10px 16px; margin-top: 10px; border-radius: 6px; border: none; font-size: 16px; }
  </style>
</head>
<body>
  <h2>Draw on the Cube</h2>
  <p>Tap a square to light it up on the physical cube in real time.</p>
  <input type="color" id="color" value="#ff2d55">
  <button onclick="clearAll()">Clear Cube</button>
  <div id="grid"></div>

  <script>
    const grid = document.getElementById('grid');
    const colorPicker = document.getElementById('color');
    const cells = [];

    for (let y = 0; y < 8; y++) {
      for (let x = 0; x < 8; x++) {
        const cell = document.createElement('div');
        cell.className = 'cell';
        cell.onclick = () => paint(x, y, cell);
        grid.appendChild(cell);
        cells.push(cell);
      }
    }

    function paint(x, y, cell) {
      const hex = colorPicker.value;
      cell.style.background = hex;
      const r = parseInt(hex.substr(1, 2), 16);
      const g = parseInt(hex.substr(3, 2), 16);
      const b = parseInt(hex.substr(5, 2), 16);
      fetch(`/pixel?x=${x}&y=${y}&r=${r}&g=${g}&b=${b}`);
    }

    function clearAll() {
      cells.forEach(c => c.style.background = '#222');
      fetch('/clear');
    }
  </script>
</body>
</html>
)HTML";

static void handleRoot()
{
    server.send_P(200, "text/html", INDEX_HTML);
}

static void handleSetPixel()
{
    if (!server.hasArg("x") || !server.hasArg("y"))
    {
        server.send(400, "text/plain", "missing x/y");
        return;
    }

    int x = server.arg("x").toInt();
    int y = server.arg("y").toInt();
    int r = server.hasArg("r") ? server.arg("r").toInt() : 255;
    int g = server.hasArg("g") ? server.arg("g").toInt() : 255;
    int b = server.hasArg("b") ? server.arg("b").toInt() : 255;

    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE)
    {
        canvas[y * GRID_SIZE + x] = CRGB(r, g, b);
    }

    server.send(200, "text/plain", "ok");
}

static void handleClear()
{
    clearCanvas();
    server.send(200, "text/plain", "ok");
}

void initWiFiCanvas()
{
    clearCanvas();

    WiFi.softAP(AP_SSID, AP_PASSWORD);

    server.on("/", handleRoot);
    server.on("/pixel", handleSetPixel);
    server.on("/clear", handleClear);

    server.begin();
    serverStarted = true;

    Serial.println("Live Canvas AP started:");
    Serial.print("  SSID: ");
    Serial.println(AP_SSID);
    Serial.print("  IP:   ");
    Serial.println(WiFi.softAPIP());
}

void clearCanvas()
{
    for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
    {
        canvas[i] = CRGB::Black;
    }
}

void runWiFiCanvas()
{
    if (!serverStarted)
    {
        return;
    }

    server.handleClient();

    // Mirror the 8x8 canvas onto every face's matrix.
    for (int face = 0; face < NUM_MATRICES; face++)
    {
        for (int i = 0; i < GRID_SIZE * GRID_SIZE; i++)
        {
            leds[(face * LEDS_PER_MATRIX) + i] = canvas[i];
        }
    }

    FastLED.show();
}
