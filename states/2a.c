#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input2.h"

#pragma bank 2

void init_2a() {
  executed = false;
}

void execute_2a() {
  uint16_t score = 0;
  for (uint16_t i = 0; i < array_2_opponent_size; i++) {
    char opponent = input_array_2_opponent[i];
    char me = input_array_2_me[i];
    if (opponent == me) {
      score += 3;
    } else if ((opponent == 'A' && me == 'B') || (opponent == 'B' && me == 'C') || (opponent == 'C' && me == 'A')) {
      score += 6;
    }

    if (me == 'A') {
      score += 1;
    } else if (me == 'B') {
      score += 2;
    } else if (me == 'C') {
      score += 3;
    }
  }
  gotoxy(0, 0);
  printf("%d", score);
  
}

void run_2a() {
  if (!executed) {
    execute_2a();
    executed = true;
  }
  wait_vbl_done();
}