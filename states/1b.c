#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input1.h"

#pragma bank 1

void init_1b() {
  executed = false;
}

void execute_b() {
  uint32_t highest_calories = 0;
  uint32_t second_highest_calories = 0;
  uint32_t third_highest_calories = 0;
  uint32_t calories = 0;
  uint32_t total_calories = 0;
  for (uint16_t i = 0; i < array_size; i++) {
    if (input_array[i] != 0) {
      calories += input_array[i];
    } else {
      if (calories > highest_calories) {
        third_highest_calories = second_highest_calories;
        second_highest_calories = highest_calories;
        highest_calories = calories;
      } else if (calories > second_highest_calories) {
        third_highest_calories = second_highest_calories;
        second_highest_calories = calories;
      } else if (calories > third_highest_calories) {
        third_highest_calories = calories;
      }
      calories = 0;
    }
  }
  gotoxy(0, 0);
  total_calories = highest_calories + second_highest_calories + third_highest_calories;
  print_32(&total_calories);
}

void run_1b() {
  if (!executed) {
    execute_b();
    executed = true;
  }
  wait_vbl_done();
}