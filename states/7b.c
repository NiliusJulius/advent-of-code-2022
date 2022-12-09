#include <gb\gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input7.h"

#pragma bank 7

void init_7b() {
  executed = false;
}

void execute_7b() {
  uint8_t parent_indexes[DIR_COUNT];
  uint32_t sizes[DIR_COUNT];
  for (uint8_t i = 0; i < DIR_COUNT; i++) {
    parent_indexes[i] = 0;
    sizes[i] = 0;
  }
  uint8_t dir_index = 0;
  uint8_t max_dir_index = 0;
  for (uint16_t i = 1; i < ARRAY_7_SIZE; i++) {
    if (input_array_7[i][0] == '$') {
      if (input_array_7[i][5] == '.') {
        sizes[parent_indexes[dir_index]] += sizes[dir_index];
        dir_index = parent_indexes[dir_index];
      } else {
        max_dir_index++;
        parent_indexes[max_dir_index] = dir_index;
        dir_index = max_dir_index; 
      }
    } else {
      sizes[dir_index] += atol(input_array_7[i]);
    }
  }

  while (dir_index > 0) {
    sizes[parent_indexes[dir_index]] += sizes[dir_index];
    dir_index = parent_indexes[dir_index];
  }

  uint32_t space_free = total_space - sizes[0];
  uint32_t min_space_to_free = space_needed - space_free;

  uint32_t smallest_dir_size = sizes[0];
  for (uint8_t i = 1; i < DIR_COUNT; i++) {
    if (sizes[i] > min_space_to_free && sizes[i] < smallest_dir_size) {
      smallest_dir_size = sizes[i];
    }
  }
  
  gotoxy(0, 0);
  char dec[16];
  ultoa(smallest_dir_size, dec, 10);
  printf(dec);
}

void run_7b() {
  if (!executed) {
    execute_7b();
    executed = true;
  }
  wait_vbl_done();
}