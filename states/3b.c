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

  uint8_t array1[53];
  uint8_t array2[53];
  uint8_t array3[53];

void init_arrays_3() {
  for (uint8_t i = 0; i < 53; i++) {
    array1[i] = 0;
    array2[i] = 0;
    array3[i] = 0;
  }
}

void execute_3b() {
  uint16_t total_prio = 0;
  for (uint16_t i = 0; i < array_3_size; i+=3) {
    uint8_t item_prio = 0;
    init_arrays_3();
    bool found_match = false;

    for (uint8_t j = 0; j < strlen(input_array_3[i]); j++) {
      if (input_array_3[i][j] > 96) {
        array1[input_array_3[i][j] - 96] = input_array_3[i][j] - 96;
      } else {
        array1[input_array_3[i][j] - 38] = input_array_3[i][j] - 38;
      }
    }

    for (uint8_t j = 0; j < strlen(input_array_3[i+1]); j++) {
      if (input_array_3[i+1][j] > 96) {
        array2[input_array_3[i+1][j] - 96] = input_array_3[i+1][j] - 96;
      } else {
        array2[input_array_3[i+1][j] - 38] = input_array_3[i+1][j] - 38;
      }
    }

    for (uint8_t j = 0; j < strlen(input_array_3[i+2]); j++) {
      if (input_array_3[i+2][j] > 96) {
        array3[input_array_3[i+2][j] - 96] = input_array_3[i+2][j] - 96;
      } else {
        array3[input_array_3[i+2][j] - 38] = input_array_3[i+2][j] - 38;
      }
    }

    for (uint8_t j = 1; j < 53; j++) {
      if (array1[j] * array2[j] * array3[j] != 0) {
        total_prio += array1[j];
        break;
      }
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