## About

This is code to have an Arduino control a slow crossfade on Coolermaster fans between a selected band of colours (hues), using the FastLed library

## ▶️ Quickstart

1. Wire the Arduino according to the diagram below
2. Open a new project in Arduino IDE
3. Open the Sketch Menu -> Include Library -> Manage Libraries and install the `FastLed` library
4. Copy the [source code](./fan_light_fader.ino) into the editor
5. Compile and Upload the code into the Arduino and watch the lights!

This project requires the [FastLed](https://github.com/FastLED/FastLED/wiki/Pixel-reference) library.

The code is shared under the [NoHarm License](./LICENSE.md)

See wiring diagrams and pictures below.

## 🛒 Components Needed

Aside from the fans themselves, you will need:

1. An Arduino Uno
2. [Breadboard male wires](https://www.aliexpress.com/w/wholesale-bread-board-male-wires.html?spm=a2g0o.productlist.search.0) (3 of them)
3. [ARGB fan cable](https://www.aliexpress.com/w/wholesale-argb-fan-cable.html?spm=a2g0o.productlist.search.0) (to extend comfortably from the Uno)
4. A USB cable and adaptor to power the Arduino OR a 12V wall plug to DC 5.5mm x 2.1mm jack

Optionally, you may also want to get a [90mm x 65mm x 35mm project box](https://www.aliexpress.com/w/wholesale-90mm-65mm-plastic-project-box.html?spm=a2g0o.productlist.search.0) to stop the Arduino and the wires from rattling around loosely and falling apart.

## 🦺 Safety

Be sure not to overload your Arduino Uno or your power supply. You will need to add up the current you need for all the fans and the Arduino.

Strictly speaking, only 0.5 Amps can be drawn when using USB to power your Arduino, and up to 0.8 Amps if using a 12V wall plug.

Check the specifications of your fans to see how much current the LED's on your fans draw (usually around 0.2 to 0.4 Amps per fan)

If you're powering the fans themselves from the same power supply, be sure to factor that in too.

For example, the [Coolermaster Sickleflow ARGB specifications]([https://www.coolermaster.com/en-global/products/sickleflow-120/?tab=tech_spec](https://www.coolermaster.com/en-global/products/sickleflow-120-argb/?tab=tech_spec)) give 0.21 Amps for the RGB and a safety current of 0.37 Amps for the fan.

So if you had 2 fans connected, that would be 0.42 Amps, plus 0.05 Amps for the Arduino Uno itself totally 0.47 Amps which is pushing pretty close to the limit for a USB power supply.

If you were sharing the same power supply to drive the fans also, then thats 0.42 Amps for the ARGB LED's, 0.05 Amps for the Arduino and 0.74 Amps for the fans - totalling 1.21 Amps.

Also be sure to use it under supervision the first time you turn it on and check the temperature of the Uno after using for 20 minutes, just in case you've made a miscalculation.

## ⚡️ Safe Power Supplies

For safety, I always buy my 12V power supplies from a local New Zealand or Australian retailer. While I get other components off AliExpress because they're cheaper, I don't want to risk compromising safety on Power Supplies. Buying those locally ensures they're complying fully with electrical standards. 

Cheap overseas powersupplies may skimp on the safety features that keep the 240V from the wall separate from the 12V of the project, and you really don't want those two things to mix.


## ➰ Wiring

Connect the 5V to the wire where the arrow is
(or if there is no arrow, to the outside wire nearest the middle wire)
Connect PIN 3 to the middle wire closest the 5V wire
Connect GND to the remaining wire on the other side.

![Photo of Wiring](./wiring%20photo.jpg)
![Example of wiring from Arduino Uno](./argb%20wiring%20diagram.png)

In a project box, with two holes drilled for the power and ARGB cables.

![In a Project Box](https://github.com/user-attachments/assets/5073296f-4166-4101-8158-8ef51145763e)


