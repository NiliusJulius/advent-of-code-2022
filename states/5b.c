#include <gb\gb.h>
#include <stdio.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\helper.h"
#include "..\inputs\input5.h"

#pragma bank 5

void init_5b() {
  executed = false;
}

void execute_5b() {
  char input_array_5_stacks_mutable[504];

  for (uint16_t i = 0; i < 504; i++) {
    input_array_5_stacks_mutable[i] = input_array_5_stacks[i];
  }

  char input_array_5_stack_counts_mutable[9];

  for (uint16_t i = 0; i < 9; i++) {
    input_array_5_stack_counts_mutable[i] = input_array_5_stack_counts[i];
  }
  
  for (uint16_t i = 0; i < array_5_size; i+=3) {
    for (uint8_t j = input_array_5[i]; j > 0 ; j--) {
      uint16_t to_index = (input_array_5[i+2]-1)*max_stack_size_5+input_array_5_stack_counts_mutable[input_array_5[i+2]-1]+j-1;
      uint16_t from_index = (input_array_5[i+1]-1)*max_stack_size_5+input_array_5_stack_counts_mutable[input_array_5[i+1]-1]-1;
      input_array_5_stacks_mutable[to_index] = input_array_5_stacks_mutable[from_index];

      input_array_5_stacks_mutable[from_index] = 0;
      input_array_5_stack_counts_mutable[input_array_5[i+1]-1]--;
    }
    input_array_5_stack_counts_mutable[input_array_5[i+2]-1] += input_array_5[i];
  }  
  
  gotoxy(0, 0);
  for (uint8_t i = 0; i < input_array_5_stacks_count; i++) {
    char top_item = input_array_5_stacks_mutable[(i)*max_stack_size_5+input_array_5_stack_counts_mutable[i]-1];
    printf("%c", (char)top_item);
  }
  
}

void run_5b() {
  if (!executed) {
    execute_5b();
    executed = true;
  }
  wait_vbl_done();
}