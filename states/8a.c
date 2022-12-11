#include <gb\gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\inputs\input8.h"

#pragma bank 8

void init_8a() {
  executed = false;
}

void execute_8a() {
  for (uint8_t i = 0; i < ARRAY_8_SIZE_Y; i++) {
    for (uint8_t j = 0; j < ARRAY_8_SIZE_X; j++) {
      giant_array[i * ARRAY_8_SIZE_X + j/8] = 0;
    }
  }
  uint16_t visible_count = 0;
  for (uint8_t y = 1; y < ARRAY_8_SIZE_Y - 1; y++) {
    uint8_t highest = input_array_8[y][0];
    for (uint8_t x = 1; x < ARRAY_8_SIZE_X - 1; x++) {
      if (input_array_8[y][x] > highest) {
        uint8_t check_bit = 0x0001 << x % 8;
        bool have_seen = giant_array[y * ARRAY_8_SIZE_X + x/8] & check_bit;
        if (!have_seen) {
          visible_count++;
          giant_array[y * ARRAY_8_SIZE_X + x/8] = giant_array[y * ARRAY_8_SIZE_X + x/8] | check_bit;
        }
        highest = input_array_8[y][x];
      }
    }
    highest = input_array_8[y][ARRAY_8_SIZE_X-1];
    for (uint8_t x = ARRAY_8_SIZE_X - 2; x > 0; x--) {
      if (input_array_8[y][x] > highest) {
        uint8_t check_bit = 0x0001 << x % 8;
        bool have_seen = giant_array[y * ARRAY_8_SIZE_X + x/8] & check_bit;
        if (!have_seen) {
          visible_count++;
          giant_array[y * ARRAY_8_SIZE_X + x/8] = giant_array[y * ARRAY_8_SIZE_X + x/8] | check_bit;
        }
        highest = input_array_8[y][x];
      }
    }
  }

  for (uint8_t x = 1; x < ARRAY_8_SIZE_X - 1; x++) {
    uint8_t highest = input_array_8[0][x];
    for (uint8_t y = 1; y < ARRAY_8_SIZE_Y - 1; y++) {
      if (input_array_8[y][x] > highest) {
        uint8_t check_bit = 0x0001 << x % 8;
        bool have_seen = giant_array[y * ARRAY_8_SIZE_X + x/8] & check_bit;
        if (!have_seen) {
          visible_count++;
          giant_array[y * ARRAY_8_SIZE_X + x/8] = giant_array[y * ARRAY_8_SIZE_X + x/8] | check_bit;
        }
        highest = input_array_8[y][x];
      }
    }
    highest = input_array_8[ARRAY_8_SIZE_Y-1][x];
    for (uint8_t y = ARRAY_8_SIZE_Y - 2; y > 0; y--) {
      if (input_array_8[y][x] > highest) {
        uint8_t check_bit = 0x0001 << x % 8;
        bool have_seen = giant_array[y * ARRAY_8_SIZE_X + x/8] & check_bit;
        if (!have_seen) {
          visible_count++;
          giant_array[y * ARRAY_8_SIZE_X + x/8] = giant_array[y * ARRAY_8_SIZE_X + x/8] | check_bit;
        }
        highest = input_array_8[y][x];
      }
    }
  }

  visible_count += ARRAY_8_SIZE_X * 2 + ARRAY_8_SIZE_Y * 2 - 4;
  gotoxy(0, 0);
  printf("%u", visible_count);
}

void run_8a() {
  if (!executed) {
    execute_8a();
    executed = true;
  }
  wait_vbl_done();
}