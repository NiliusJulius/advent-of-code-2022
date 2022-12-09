#include <gb\gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\inputs\input8.h"

#pragma bank 8

void init_8b() {
  executed = false;
}

void execute_8b() {
  uint32_t scenic_score = 0;
  for (uint8_t y = 1; y < ARRAY_8_SIZE_Y - 1; y++) {
    for (uint8_t x = 1; x < ARRAY_8_SIZE_X - 1; x++) {
      uint32_t temp_scenic_score = 0;
      for (uint8_t offset_x = 0 ; x - offset_x > 0; offset_x++) {
        if (input_array_8[y][x - offset_x - 1] >= input_array_8[y][x] || x - offset_x - 1 == 0) {
          temp_scenic_score += offset_x + 1;
          break;
        }
      }

      for (uint8_t offset_x = 0 ; x + offset_x < ARRAY_8_SIZE_X - 1; offset_x++) {
        if (input_array_8[y][x + offset_x + 1] >= input_array_8[y][x] || x + offset_x == ARRAY_8_SIZE_X - 2) {
          temp_scenic_score *= offset_x + 1;
          break;
        }
      }

      for (uint8_t offset_y = 0 ; x - offset_y > 0; offset_y++) {
        if (input_array_8[y - offset_y - 1][x] >= input_array_8[y][x] || y - offset_y - 1 == 0) {
          temp_scenic_score *= offset_y + 1;
          break;
        }
      }

      for (uint8_t offset_y = 0 ; y + offset_y < ARRAY_8_SIZE_Y - 1; offset_y++) {
        if (input_array_8[y + offset_y + 1][x] >= input_array_8[y][x] || y + offset_y == ARRAY_8_SIZE_Y - 2) {
          temp_scenic_score *= offset_y + 1;
          break;
        }
      }

      if (temp_scenic_score > scenic_score) {
        scenic_score = temp_scenic_score;
      }
    }
  }

  gotoxy(0, 0);
  char dec[10];
  ultoa(scenic_score, dec, 10);
  printf(dec);
}

void run_8b() {
  if (!executed) {
    execute_8b();
    executed = true;
  }
  wait_vbl_done();
}