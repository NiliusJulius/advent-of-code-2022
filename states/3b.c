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
    bool found_match = false;
    for (uint8_t j = 0; j < strlen(input_array_3[i]); j++) {
      for (uint8_t k = 0; k < strlen(input_array_3[i+1]); k++) {
        for (uint8_t l = 0; l < strlen(input_array_3[i+2]); l++) {
          if (input_array_3[i][j] == input_array_3[i+1][k] && input_array_3[i][j] == input_array_3[i+2][l]) {
            if (input_array_3[i][j] > 96) {
              item_prio = input_array_3[i][j] - 96;
            } else {
              item_prio = input_array_3[i][j] - 38;
            }
            found_match = true;
          }
          if (found_match) break;
        }
        if (found_match) break;
      }
      if (found_match) break;
    }
    total_prio += item_prio;
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