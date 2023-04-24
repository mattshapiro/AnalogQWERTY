#include "AnalogQWERTY.h"

// analog voltage values
const int voltages[] = 
  {1023, 930, 853, 788,
   701, 657, 617, 582,
   534, 507, 483, 461,
   431, 413, 397, 382};

const char layouts[3][ROWS][COLS] = 
  {
   {
    {'1', '2', '3', '4'},
    {'q', 'w', 'e', 'r'},
    {'a', 's', 'd', 'f'},
    {'z', 'x', 'c', 'v'}
   },
   {
    {'5', '6', '7', '8'},
    {'t', 'y', 'u', 'i'},
    {'g', 'h', 'j', 'k'},
    {' ', ' ', ' ', ' '}
   },
   {
    {'9', '0', '-', DELETE_KEY},
    {'o', 'p', '+', '?'},
    {'l', ',', '\"', RETURN_KEY},    
    {'b', 'n', 'm', ';'}    
   }
  };

void AnalogQWERTY::init(int *in_pins, int num_pins) {
     voltages_size = sizeof(voltages) / sizeof(voltages[0]);
     pins = in_pins;
     this->num_pins = num_pins;
     lastKey = NULL;
};

char AnalogQWERTY::getKeyPress() { 
    bool pressed = false;
    for (int i = 0; i < num_pins; i++ ){
        int temp = analogRead(pins[i]);
        if(temp > 50) {
            pressed = true;
            for (int j = 0; j < voltages_size; j++){
                if ((voltages[j] - VARIANCE <= temp) && (voltages[j] + VARIANCE >= temp)){
                    int row = j / ROWS;
                    int col = j % COLS;
                    char ch = layouts[i][row][col];
                    if(ch != lastKey) {
                        // hacky debounce
                        lastKey = ch;
                        return ch;
                    }
                }
            }  
        }
    }

    if(!pressed) { 
        // key is up
        lastKey = NULL; 
    }

    return NULL;
};
