#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\inputs\input1.h"

#pragma bank 1

uint16_t increases_b;
bool executed_b;

void init_1b() {
  increases_b = 0;
  executed_b = false;
}

void execute_b() {
  for (uint16_t i = 2; i < 1999; i++) {
    if (input_array[i+1] > input_array[i-2]) {
      increases_b++;
    }
  }
  gotoxy(0, 0);
  printf("%d", increases_b);
}

void run_1b() {
  if (!executed_b) {
    execute_b();
    executed_b = true;
  }
  wait_vbl_done();
}