#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input2.h"

#pragma bank 2

void init_2b() {
  executed = false;
}

void execute_2b() {
  uint16_t score = 0;
  for (uint16_t i = 0; i < array_2_me_size; i++) {
    char opponent = input_array_2_opponent[i];
    char me;
    if (input_array_2_me[i] == 'C') {
      me = opponent + 1;
      score += 6;
    } else if (input_array_2_me[i] == 'A') {
      me = opponent - 1;
    } else {
      me = opponent;
      score += 3;
    }

    if (me < 'A') {
      me = 'C';
    } else if (me > 'C') {
      me = 'A';
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

void run_2b() {
  if (!executed) {
    execute_2b();
    executed = true;
  }
  wait_vbl_done();
}