#include "AnalogQWERTY.h"

#define STM32
//#define ATMEGA328

#ifdef STM32
#define NUM_KEYPADS 3
int PINS[] = { PA6, PB0, PB1 };
#endif

#ifdef UNO || NANO
#define NUM_KEYPADS 3
int PINS[] = { A0, A1, A2 };
#endif

AnalogQWERTY keyboard;

void setup() {
  // put your setup code here, to run once:
  keyboard = AnalogQWERTY();
  keyboard.init(&PINS[0], NUM_KEYPADS);
  Serial.begin(9600);
  delay(1000);
  Serial.println("initialized");
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keyboard.getKeyPress();

  if(key == DELETE_KEY) {
    // delete pressed
  } else if (key == RETURN_KEY) {
    // return pressed
  } else if(key != NULL) {
    Serial.print(key);
  }
  delay(100);
}
