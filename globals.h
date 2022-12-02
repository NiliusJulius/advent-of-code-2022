#ifndef _GLOBALS
#define _GLOBALS

#include <stdint.h>
#include <stdbool.h>
#include <gbdk\bcd.h>
#include "typedefs.h"

#define UPDATE_KEYS()	prev_input = curr_input; curr_input = joypad()
#define KEY_PRESSED(K)	(curr_input & (K))
#define KEY_DEBOUNCE(K) ((curr_input & (K)) && (prev_input & (K)))
#define KEY_TICKED(K)   ((curr_input & (K)) && !(prev_input & (K)))
#define KEY_RELEASED(K) ((prev_input & (K)) && !(curr_input & (K)))

extern uint8_t curr_input;
extern uint8_t prev_input;

#define STATE_INTRO 0
#define STATE_1A 1
#define STATE_1B 2
#define STATE_2A 3
#define STATE_2B 4
#define STATE_3A 5
#define STATE_3B 6
#define STATE_4A 7
#define STATE_4B 8
#define STATE_5A 9
#define STATE_5B 10
#define STATE_6A 11
#define STATE_6B 12
#define STATE_7A 13
#define STATE_7B 14
#define STATE_8A 15
#define STATE_8B 16
#define STATE_9A 17
#define STATE_9B 18
#define STATE_10A 19
#define STATE_10B 20
#define STATE_11A 21
#define STATE_11B 22
#define STATE_12A 23
#define STATE_12B 24
#define STATE_13A 25
#define STATE_13B 26
#define STATE_14A 27
#define STATE_14B 28
#define STATE_15A 29
#define STATE_15B 30
#define STATE_16A 31
#define STATE_16B 32
#define STATE_17A 33
#define STATE_17B 34
#define STATE_18A 35
#define STATE_18B 36
#define STATE_19A 37
#define STATE_19B 38
#define STATE_20A 39
#define STATE_20B 40
#define STATE_21A 41
#define STATE_21B 42
#define STATE_22A 43
#define STATE_22B 44
#define STATE_23A 45
#define STATE_23B 46
#define STATE_24A 47
#define STATE_24B 48
#define STATE_25A 49
#define STATE_25B 50

extern uint8_t state;
extern bool executed;

extern void execute();

#endif