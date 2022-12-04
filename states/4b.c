#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input4.h"

#pragma bank 4

void init_4b() {
  executed = false;
}

void execute_4b() {
  uint16_t overlap_count = 0;
  
  for (uint16_t i = 0; i < array_4_size; i+=4) {
    if ((input_array_4[i] <= input_array_4[i+2] && input_array_4[i+1] >= input_array_4[i+2])
          || (input_array_4[i] <= input_array_4[i+3] && input_array_4[i+1] >= input_array_4[i+2])
        ) {
      overlap_count++;
    }
  }  
  
  gotoxy(0, 0);
  printf("%u", overlap_count);
  
}

void run_4b() {
  if (!executed) {
    execute_4b();
    executed = true;
  }
  wait_vbl_done();
}