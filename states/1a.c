#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\inputs\input1.h"

#pragma bank 1

uint16_t increases;
bool executed;

void init_1a() {
  increases = 0;
  executed = false;
}

void execute() {
  for (uint16_t i = 0; i < 1999; i++) {
    if (input_array[i+1] > input_array[i]) {
      increases++;
    }
  }
  gotoxy(0, 0);
  printf("%d", increases);
}

void run_1a() {
  if (!executed) {
    execute();
    executed = true;
  }
  wait_vbl_done();
}