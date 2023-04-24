# AnalogQWERTY
Arduino library to stitch muliple 4x4 matrix keypads into an analog QWERTY keyboard for Arduino &amp; STM32 microcontrollers.

Requires a voltage bridge circuit (see primitive schematic below) consisting of three 2.2k ohm resistors connected in series between the rows and three 10k resistors connected between the columns. Since the rows & columns are multiplexed, each key combination should create its own unique voltage* which is sent to a microcontroller's analog pin (with a pull down resistor on the common ground to default LOW)**

![schematic](https://user-images.githubusercontent.com/966612/232648664-235c39d4-0644-4b88-b584-92e075c47788.jpeg)
(Build 3 of these to string 3 keypads together for 48 keys - MORE than enough for a modest QWERTY layout!!)

\* technically a range of voltages which have only been tessted at room temperature so far ha ha ha

\*\* I am a total electronoob if you couldn't tell. Feedback greatly appreciated!
