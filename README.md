## About

This is code to have an Arduino control a slow crossfade on Coolermaster fans between a selected band of colours (hues), using the FastLed library

## Quickstart

1. Wire the Arduino according to the diagram below
2. Open a new project in Arduino IDE
3. Open the Sketch Menu -> Include Library -> Manage Libraries and install the FastLed library
4. Cope the [source code](./fan_light_fader.ino) into the editor
5. Compile and Upload the code into the Arduino and watch the lights!



This project requires the [FastLed](https://github.com/FastLED/FastLED/wiki/Pixel-reference) library.

The code is shared under the [NoHarm License](./LICENSE.md)

## Wiring

Connect PIN 3 to the middle wire, 5V to the wire closest to that, and then GND to the remaining wire on the other side.

![Example of wiring from Arduino Uno](./argb%20wiring%20diagram.png)


