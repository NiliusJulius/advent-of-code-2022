#include <gb\gb.h>
#include <stdio.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input3.h"

#pragma bank 3

void init_3a() {
  executed = false;
}

void execute_3a() {
  uint16_t total_prio = 0;
  for (uint16_t i = 0; i < array_3_size; i++) {
    uint8_t half_length = strlen(input_array_3[i]) / 2;
    uint8_t array1[53];
    uint8_t array2[53];
    for (uint8_t k = 0; k < 53; k++) {
      array1[k] = 0;
      array2[k] = 0;
    }
    for (uint8_t j = 0; j < half_length; j++) {
      uint8_t index = input_array_3[i][j];
      if ( index > 96) {
        array1[index - 96] = 1;
      } else {
        array1[index - 38] = 1;
      }
    }

    for (uint8_t j = half_length; j < strlen(input_array_3[i]); j++) {
      uint8_t index = input_array_3[i][j];
      if (index > 96) {
        array2[index - 96] = array1[index - 96] * (index - 96);
      } else {
        array2[index - 38] = array1[index - 38] * (index - 38);
      }
    }

    for (uint8_t j = 1; j < 53; j++) {
        total_prio += array2[j];
    }
  }
  gotoxy(0, 0);
  printf("%d", total_prio);
  
}

void run_3a() {
  if (!executed) {
    execute_3a();
    executed = true;
  }
  wait_vbl_done();
}