#include <gb\gb.h>
#include <stdio.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input6.h"

#pragma bank 6

void init_6a() {
  executed = false;
}

void execute_6a() {
  uint16_t alphabet[26];
  for (uint8_t i = 0; i < 26; i++) {
    alphabet[i] = 0;
  }
  uint16_t last_match_index = 0;
  for (uint16_t i = 0; i < array_6_size; i++) {
    if (alphabet[input_array_6[i]-97] + 4 > i && alphabet[input_array_6[i]-97] > 0 && last_match_index < alphabet[input_array_6[i]-97]) {
      last_match_index = alphabet[input_array_6[i]-97];
    }
    alphabet[input_array_6[i]-97] = i;

    if (last_match_index + 3 < i) {
      gotoxy(0, 0);
      printf("%u", i + 1);
      break;
    }
  }  
}

void run_6a() {
  if (!executed) {
    execute_6a();
    executed = true;
  }
  wait_vbl_done();
}