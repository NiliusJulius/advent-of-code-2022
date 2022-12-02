#include <stdint.h>
#include <stdbool.h>
#include "globals.h"
#include <gb\bcd.h>
#include "typedefs.h"

uint8_t curr_input;
uint8_t prev_input;

uint8_t state;
bool executed;