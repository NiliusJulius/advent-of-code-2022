#include <gb\gb.h>
#include <stdio.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input3.h"

#pragma bank 3

void init_3b() {
  executed = false;
}

void execute_3b() {
  uint16_t total_prio = 0;
  for (uint16_t i = 0; i < array_3_size; i+=3) {
    uint8_t item_prio = 0;

    uint8_t array1[53];
    uint8_t array2[53];
    uint8_t array3[53];
    for (uint8_t i = 0; i < 53; i++) {
      array1[i] = 0;
      array2[i] = 0;
      array3[i] = 0;
    }
    bool found_match = false;

    for (uint8_t j = 0; j < strlen(input_array_3[i]); j++) {
      uint8_t index = input_array_3[i][j];
      if ( index > 96) {
        array1[index - 96] = 1;
      } else {
        array1[index - 38] = 1;
      }
    }

    for (uint8_t j = 0; j < strlen(input_array_3[i+1]); j++) {
      uint8_t index = input_array_3[i+1][j];
      if ( index > 96) {
        array2[index - 96] = 1;
      } else {
        array2[index - 38] = 1;
      }
    }

    for (uint8_t j = 0; j < strlen(input_array_3[i+2]); j++) {
      uint8_t index = input_array_3[i+2][j];
      if (index > 96) {
        array3[index - 96] = array2[index - 96] * array1[index - 96] * (index - 96);
      } else {
        array3[index - 38] = array2[index - 38] * array1[index - 38] * (index - 38);
      }
    }

    for (uint8_t j = 1; j < 53; j++) {
        total_prio += array3[j];
    }
  }
  gotoxy(0, 0);
  printf("%d", total_prio);
  
}

void run_3b() {
  if (!executed) {
    execute_3b();
    executed = true;
  }
  wait_vbl_done();
}