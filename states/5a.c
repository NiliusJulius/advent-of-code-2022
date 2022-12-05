#include <gb\gb.h>
#include <stdio.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input5.h"

#pragma bank 5

void init_5a() {
  executed = false;
}

void execute_5a() {
  for (uint16_t i = 0; i < array_5_size; i+=3) {
    for (uint8_t j = 0; j < input_array_5[i]; j++) {
      uint16_t to_index = (input_array_5[i+2]-1)*max_stack_size_5+input_array_5_stack_counts[input_array_5[i+2]-1];
      uint16_t from_index = (input_array_5[i+1]-1)*max_stack_size_5+input_array_5_stack_counts[input_array_5[i+1]-1]-1;
      input_array_5_stacks[to_index] = input_array_5_stacks[from_index];

      input_array_5_stacks[from_index] = 0;
      input_array_5_stack_counts[input_array_5[i+2]-1]++;
      input_array_5_stack_counts[input_array_5[i+1]-1]--;
    }
  }  
  
  gotoxy(0, 0);
  for (uint8_t i = 0; i < input_array_5_stacks_count; i++) {
    printf("%c", input_array_5_stacks[(i)*max_stack_size_5+input_array_5_stack_counts[i]-1]);
  }
  
}

void run_5a() {
  if (!executed) {
    execute_5a();
    executed = true;
  }
  wait_vbl_done();
}