#include <gb\gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gbdk\console.h>
#include "..\globals.h"
#include "..\inputs\input10.h"
#include "..\sprites\het_blok_sprite.h"

#pragma bank 10

void init_10b() {
  executed = false;

  set_bkg_data(96, 3, het_blok_sprite);
}

void execute_10b() {
  int8_t cycle = 0;
  int16_t register_x = 1;
  uint16_t crt_y = 0;

  for (uint16_t i = 0; i < ARRAY_10_SIZE; i++) {
    int8_t register_x_increment = 0;
    uint8_t cycle_increment = 0;
    switch (input_array_10_1[i]) {
      case 'n':
        cycle_increment = 1;
        break;
      case 'a':
        cycle_increment = 2;
        register_x_increment = input_array_10_2[i];
        break;
      default:
        break;
    }
    
    for (uint8_t j = 0; j < cycle_increment; j++) {
      if (cycle >= register_x - 1 && cycle <= register_x + 1) {
        uint8_t x = cycle % 40;
        uint8_t tile = 97;
        if (x % 2 == 1) {
          x = x / 2 + 1;
          if (get_bkg_tile_xy(x-1, crt_y) == 97) {
            tile = 96;
          } else {
            tile = 98;
          }
          x -= 1;
        } else {
          x = x / 2;
        }
        set_bkg_tile_xy(x, crt_y, tile);
        wait_vbl_done();
      }
      cycle++;
      if (cycle > 39) {
        cycle = 0;
        crt_y++;
      }
    }
    register_x += register_x_increment;
  }  
}

void run_10b() {
  if (!executed) {
    execute_10b();
    executed = true;
  }
  wait_vbl_done();
}