#include <gb\gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\inputs\input10.h"

#pragma bank 10

void init_10a() {
  executed = false;
}

void execute_10a() {
  uint16_t cycle = 0;
  int16_t register_x = 1;
  int16_t strength_sum = 0;

  for (uint16_t i = 0; i < ARRAY_10_SIZE; i++) {
    int8_t register_x_increment = 0;
    uint8_t cycle_increment = 0;
    switch (input_array_10_1[i]) {
      case 'n':
        cycle_increment = 1;
        break;
      case 'a':
        cycle_increment = 2;
        register_x_increment = input_array_10_2[i];
        break;
      default:
        break;
    }
    
    for (uint8_t j = 0; j < cycle_increment; j++) {
      cycle++;
      if (cycle > 19 && (cycle - 20) % 40 == 0) {
        strength_sum += register_x * cycle;
      }
    }
    register_x += register_x_increment;
  }  

  gotoxy(0, 0);
  printf("%u", strength_sum);
}

void run_10a() {
  if (!executed) {
    execute_10a();
    executed = true;
  }
  wait_vbl_done();
}