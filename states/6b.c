#include <gb\gb.h>
#include <stdio.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input6.h"

#pragma bank 6

void init_6b() {
  executed = false;
}

void execute_6b() {
  uint16_t alphabet[26] = {0};
  uint16_t last_match_index = 0;
  for (uint16_t i = 0; i < array_6_size; i++) {
    if (alphabet[input_array_6[i]-97] + 14 > i && alphabet[input_array_6[i]-97] > 0 && last_match_index < alphabet[input_array_6[i]-97]) {
      last_match_index = alphabet[input_array_6[i]-97];
    }
    alphabet[input_array_6[i]-97] = i;

    if (last_match_index + 13 < i) {
      gotoxy(0, 0);
      printf("%u", i + 1);
      break;
    }
  }  
}

void run_6b() {
  if (!executed) {
    execute_6b();
    executed = true;
  }
  wait_vbl_done();
}