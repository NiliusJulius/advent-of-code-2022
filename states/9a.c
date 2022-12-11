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

void init_9a() {
  executed = false;
}

void update_tail(uint16_t *head_y, uint16_t *head_x, uint16_t *tail_y, uint16_t *tail_x) {
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
      *tail_y = *head_y;
    } else if (*head_x < *tail_x - 1) {
      (*tail_x)--;
      *tail_y = *head_y;
    } else if (*head_y > *tail_y + 1) {
      (*tail_y)++;
      *tail_x = *head_x;
    } else if (*head_y < *tail_y - 1) {
      (*tail_y)--;
      *tail_x = *head_x;
    }
  }
}

void execute_9a() {
  for (uint16_t i = 0; i < (uint16_t)ARRAY_9_SIZE_TOTAL; i++) {
    giant_array[i] = 0;
  }

  uint16_t head_y = STARTING_LOCATION_Y;
  uint16_t head_x = STARTING_LOCATION_X;
  uint16_t tail_y = STARTING_LOCATION_Y;
  uint16_t tail_x = STARTING_LOCATION_X;

  for (uint16_t i = 0; i < ARRAY_9_SIZE; i++) {
    for (uint8_t j = 0; j < input_array_9_2[i]; j++) {
      if (input_array_9_1[i] == 'U') {
        head_y--;
      } else if (input_array_9_1[i] == 'D') {
        head_y++;
      } else if (input_array_9_1[i] == 'L') {
        head_x--;
      } else {
        head_x++;
      }
      update_tail(&head_y, &head_x, &tail_y, &tail_x);
      
      if (tail_x < 200) {
        uint16_t loc = tail_y * ARRAY_9_SIZE_X + tail_x/8;
        giant_array[loc] = giant_array[loc] | 0x0001 << tail_x % 8;
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

  head_y = STARTING_LOCATION_Y;
  head_x = STARTING_LOCATION_X;
  tail_y = STARTING_LOCATION_Y;
  tail_x = STARTING_LOCATION_X;

  for (uint16_t i = 0; i < ARRAY_9_SIZE; i++) {
    for (uint8_t j = 0; j < input_array_9_2[i]; j++) {
      if (input_array_9_1[i] == 'U') {
        head_y--;
      } else if (input_array_9_1[i] == 'D') {
        head_y++;
      } else if (input_array_9_1[i] == 'L') {
        head_x--;
      } else {
        head_x++;
      }
      update_tail(&head_y, &head_x, &tail_y, &tail_x);

      if (tail_x >= 200) {
        uint16_t loc = tail_y * ARRAY_9_SIZE_X + (tail_x-200)/8;
        giant_array[loc] = giant_array[loc] | 0x0001 << (tail_x-200) % 8;
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

void run_9a() {
  if (!executed) {
    execute_9a();
    executed = true;
  }
  wait_vbl_done();
}