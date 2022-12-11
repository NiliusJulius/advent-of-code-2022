#include <gb\gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\inputs\input9.h"

#pragma bank 9

#define ARRAY_9_SIZE_Y 255
#define ARRAY_9_SIZE_X 25
#define ARRAY_9_SIZE_TOTAL 6375
#define STARTING_LOCATION_Y 128
#define STARTING_LOCATION_X 80

void init_9b() {
  executed = false;
}

void update_tail_b(uint16_t *head_y, uint16_t *head_x, uint16_t *tail_y, uint16_t *tail_x) {
  if (*head_y == *tail_y) {
    if (*head_x > *tail_x + 1) {
      (*tail_x)++;
    } else if (*head_x < *tail_x - 1) {
      (*tail_x)--;
    }
  } else if (*head_x == *tail_x) {
    if (*head_y > *tail_y + 1) {
      (*tail_y)++;
    } else if (*head_y < *tail_y - 1) {
      (*tail_y)--;
    }
  } else {
    if (*head_x > *tail_x + 1) {
      (*tail_x)++;
      if (*head_y > *tail_y) {
        (*tail_y)++;
      } else {
        (*tail_y)--;
      }
    } else if (*head_x < *tail_x - 1) {
      (*tail_x)--;
      if (*head_y > *tail_y) {
        (*tail_y)++;
      } else {
        (*tail_y)--;
      }
    } else if (*head_y > *tail_y + 1) {
      (*tail_y)++;
      if (*head_x > *tail_x) {
        (*tail_x)++;
      } else {
        (*tail_x)--;
      }
    } else if (*head_y < *tail_y - 1) {
      (*tail_y)--;
      if (*head_x > *tail_x) {
        (*tail_x)++;
      } else {
        (*tail_x)--;
      }
    }
  }
}

void execute_9b() {
  for (uint16_t i = 0; i < (uint16_t)ARRAY_9_SIZE_TOTAL; i++) {
    giant_array[i] = 0;
  }

  uint16_t positions[20];
  for (uint8_t i = 0; i < 20; i = i + 2) {
    positions[i] = STARTING_LOCATION_Y;
    positions[i+1] = STARTING_LOCATION_X;
  }

  for (uint16_t i = 0; i < ARRAY_9_SIZE; i++) {
    for (uint8_t j = 0; j < input_array_9_2[i]; j++) {
      if (input_array_9_1[i] == 'U') {
        positions[0] = positions[0] - 1;
      } else if (input_array_9_1[i] == 'D') {
        positions[0] = positions[0] + 1;
      } else if (input_array_9_1[i] == 'L') {
        positions[1] = positions[1] - 1;
      } else {
        positions[1] = positions[1] + 1;
      }

      for (uint8_t k = 0; k < 18; k = k+2) {
        update_tail_b(&positions[k], &positions[k+1], &positions[k+2], &positions[k+3]);
      }
        
      if (positions[19] < 200) {
        uint16_t loc = positions[18] * ARRAY_9_SIZE_X + positions[19]/8;
        giant_array[loc] = giant_array[loc] | 0x0001 << positions[19] % 8;
      }
      
    }
  }

  uint16_t visited_counter = 0;
  for (uint8_t i = 0; i < ARRAY_9_SIZE_Y; i++) {
    for (uint16_t j = 0; j < ARRAY_9_SIZE_X; j++) {
      uint8_t num = giant_array[i * ARRAY_9_SIZE_X + j];
      while (num) {
        visited_counter += num & 1;
        num >>= 1;
      }
      giant_array[i * ARRAY_9_SIZE_X + j] = 0;
    }
  }

  for (uint8_t i = 0; i < 20; i = i + 2) {
    positions[i] = STARTING_LOCATION_Y;
    positions[i+1] = STARTING_LOCATION_X;
  }

  for (uint16_t i = 0; i < ARRAY_9_SIZE; i++) {
    for (uint8_t j = 0; j < input_array_9_2[i]; j++) {
      if (input_array_9_1[i] == 'U') {
        positions[0] = positions[0] - 1;
      } else if (input_array_9_1[i] == 'D') {
        positions[0] = positions[0] + 1;
      } else if (input_array_9_1[i] == 'L') {
        positions[1] = positions[1] - 1;
      } else {
        positions[1] = positions[1] + 1;
      }
      
      for (uint8_t k = 0; k < 18; k = k+2) {
        update_tail_b(&positions[k], &positions[k+1], &positions[k+2], &positions[k+3]);
      }

      if (positions[19] >= 200) {
        uint16_t loc = positions[18] * ARRAY_9_SIZE_X + (positions[19]-200)/8;
        giant_array[loc] = giant_array[loc] | 0x0001 << (positions[19]-200) % 8;
      }
      
    }
  }

  for (uint8_t i = 0; i < ARRAY_9_SIZE_Y; i++) {
    for (uint16_t j = 0; j < ARRAY_9_SIZE_X; j++) {
      uint8_t num = giant_array[i * ARRAY_9_SIZE_X + j];
      while (num) {
        visited_counter += num & 1;
        num >>= 1;
      }
    }
  }
  

  gotoxy(0, 0);
  printf("%u", visited_counter);
}

void run_9b() {
  if (!executed) {
    execute_9b();
    executed = true;
  }
  wait_vbl_done();
}