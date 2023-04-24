#include <Arduino.h>

#ifndef ANALOGQWERTY_H
#define ANALOGQWERTY_H

#define VARIANCE 5  // ALLOWABLE VARIATION BETWEEN VOLTAGE DROPS
#define THRESHOLD 50  // 0 - THRESHOLD voltages IGNORED
#define COLS 4
#define ROWS 4

#define DELETE_KEY 0x7F
#define RETURN_KEY 0x0D
#define TEMINATOR_KEY 0x1A // for terminating SMS message bodies

class AnalogQWERTY {
    public:
        char getKeyPress();
        void init(int *in_pins, int num_pins);
    private:
        int voltages_size, num_pins;
        int *pins;
        char lastKey;
};

#endif