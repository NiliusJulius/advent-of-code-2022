#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input1.h"

#pragma bank 1

bool executed;

void init_1a() {
  executed = false;
}

void execute() {
  uint32_t highest_calories = 0;
  uint32_t calories = 0;
  for (uint16_t i = 0; i < array_size; i++) {
    if (input_array[i] != 0) {
      calories += input_array[i];
      if (calories > highest_calories) {
        highest_calories = calories;
      }
    } else {
      calories = 0;
    }
  }
  gotoxy(0, 0);
  print_32(&highest_calories);
  
}

void run_1a() {
  if (!executed) {
    execute();
    executed = true;
  }
  wait_vbl_done();
}