
# Interactive LED Cube

A custom-designed interactive LED cube that combines motion sensing, sound visualization, and real-time lighting effects into a portable display powered by an ESP32.

> Built from scratch using Fusion 360, PlatformIO, WS2812B LED matrices, an MPU6050 IMU, and a MAX4466 microphone.

##How it works

The cube uses multiple WS2812B RGB LED matrices that are mounted on its faces and is controlled by an ESP32. An IMU sensor detects thr movement, while a microphone gets the sound. The ESP32 reievee the info from this sensor data and updates the LEDs within milliseconds, which is allowing the cube to react dysnmically and smoothy.

##Why I made it

I made this project because my cousin loves LED toys and interactive lights. Seeing how he so amazed by colorful displays inspired me to create something that combines engineering, programming, and creativity. I wanted to build a device that is both entertaining and educational for him while giving me experience in that I would never forogot.

## Features
Interactive Modes

🌈 Ambient Flow

Smooth rainbow gradients

🔥 Fire

Simulated flame effect

🎵 Music Visualizer

Responds to microphone input

📳 Motion Mode

Shake triggers explosion
Tilt changes animation direction

🎮 Demo Mode

Automatically showcases every feature

eal-time response under 500 ms

## Components
- ESP32
- WS2812B LED matrices
- MPU6050
- Microphone

## Firmware
The firmware is organized into independent modules so each subsystem has a single responsibility.

- animations.cpp → Animation controller
- led_effects.cpp → LED rendering
- microphone.cpp → Audio processing
- motion.cpp → IMU processing
- button.cpp → User input
- cube_state.cpp → Shared sensor state
- main.cpp → Main control loop



## Build Log

See docs/build_log.md for project progress and development history.

## CAD Render
<img width="711" height="660" alt="Screenshot 2026-06-21 134044" src="https://github.com/user-attachments/assets/8bf18238-1645-425f-990e-a661f17b8df1" />


<img width="1464" height="848" alt="Screenshot 2026-06-15 222832" src="https://github.com/user-attachments/assets/79734bfa-ba1c-42e3-a499-0ab3df02985b" />



