# Arduino-PS2-Mouse-Handler
PS2 Mouse Handler Library for Arduinos
This library allows you to easily interface any PS2 compatible mouse to your Arduino using only 2 digital I/O pins. Most USB mice will allow you to connect them as PS2 mice. Use the D+ line as the PS2 clock signal and the D- line as the PS2 data signal.
It is based on the code by kristopher which can be found at https://github.com/kristopher/PS2-Mouse-Arduino.
I've included a basic example which shows how to gather the data from the mouse and access the x / y movement, scroll wheel, button states and button click data.
# Installation
Download and unzip the repository. Copy the folder to the Arduino library folder on your development machine. Restart your Arduino IDE and you should have access to the library in your sketches. Look for the PS2MouseHandler section in the examples for a basic implimentation of the code. The example reports data through the serial monitor.
# How to use the Handler
Include the library header file

```C++
#include <PS2MouseHandler.h>
```

Specify your data and clock pins. If you're using a USB mouse D+ is the PS2 clock signal, D- is the PS2 data signal.

```C++
#define MOUSE_DATA 5
#define MOUSE_CLOCK 6
```
Instantiate an instance of the PS2MouseHandler


```C++
PS2MouseHandler mouse(MOUSE_CLOCK, MOUSE_DATA, PS2_MOUSE_REMOTE);
```

Call the initialise() method to set up the mouse

```C++

mouse.initialise();
```

This method will return 0 if everything is OK. Non zero return value is an error. At the moment the only error is if the mouse fails to respond.
Call the get_data() method regularly to gather the movement data from the mouse.

```C++
mouse.get_data();
```

You can then access the mouse data through a number of access methods.

```C++
void mouse.get_data();
uint8_t mouse.device_id(); // device id
uint8_t mouse.status(); // Status Byte
int16_t mouse.x_movement(); // X Movement Data
int16_t mouse.y_movement(); // Y Movement Data
int8_t mouse.z_movement(); // Z Movement Data - scroll wheel
bool mouse.button(0); // get status of left mouse button
bool mouse.button(1); // get status of middle mouse button
bool mouse.button(2); // get status of right mouse button
bool mouse.clicked(0); // has left button been clicked this update?
bool mouse.clicked(1); // has middle button been clicked this update?
bool mouse.clicked(2); // has right button been clicked this update?
```

