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
    uint8_t item_prio = 0;
    for (uint8_t j = 0; j < half_length; j++) {
      for (uint8_t k = half_length; k < half_length * 2; k++) {
        if (input_array_3[i][j] == input_array_3[i][k]) {
          if (input_array_3[i][j] > 96) {
            item_prio = input_array_3[i][j] - 96;
          } else {
            item_prio = input_array_3[i][j] - 38;
          }
        }
      }
    }
    total_prio += item_prio;
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