#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input4.h"

#pragma bank 4

void init_4a() {
  executed = false;
}

void execute_4a() {
  uint16_t full_overlap_count = 0;
  
  for (uint16_t i = 0; i < array_4_size; i+=4) {
    if ((input_array_4[i] <= input_array_4[i+2] && input_array_4[i+1] >= input_array_4[i+3])
          || (input_array_4[i] >= input_array_4[i+2] && input_array_4[i+1] <= input_array_4[i+3])
        ) {
      full_overlap_count++;
    }
  }  
  
  gotoxy(0, 0);
  printf("%u", full_overlap_count);
  
}

void run_4a() {
  if (!executed) {
    execute_4a();
    executed = true;
  }
  wait_vbl_done();
}