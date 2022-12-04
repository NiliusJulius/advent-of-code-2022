#include <gb\gb.h>
#include "..\globals.h"
#include "..\maps\intro_map.h"
#include "..\maps\blank_map.h"
#include "..\sprites\pointer_sprite.h"

#include "..\states\1a.h"
#include "..\states\1b.h"
#include "..\states\2a.h"
#include "..\states\2b.h"
#include "..\states\3a.h"
#include "..\states\3b.h"
#include "..\states\4a.h"
#include "..\states\4b.h"

uint8_t menu_item;

void init_intro() {
  HIDE_WIN;
  SHOW_SPRITES;
  SHOW_BKG;

  set_bkg_tiles(0, 0, 20, 18, intro_map);
  set_sprite_data(1, 1, pointer_sprite);

  menu_item = 0;
  set_sprite_tile(0, 1);
  move_sprite(0, 16, 16);

}

void clear_screen() {
  set_bkg_tiles(0, 0, 20, 18, blank_map);
  move_sprite(0, 0, 0);
}

void move_pointer() {
  move_sprite(0, 16+54*(menu_item/18), 16+8*(menu_item%18));
}

void run_intro() {
  if (KEY_TICKED(J_UP)) {
    if (menu_item == 0) {
      menu_item = 24;
    } else {
      menu_item -= 1;
    }
    move_pointer();
  }

  if (KEY_TICKED(J_DOWN)) {
    if (menu_item == 24) {
      menu_item = 0;
    } else {
      menu_item += 1;
    }
    move_pointer();
  }

  if (KEY_TICKED(J_A)) {
    switch (menu_item) {
      case 0:
        SWITCH_ROM(1);
        init_1a();
        state = STATE_1A;
        break;
      case 1:
        SWITCH_ROM(2);
        init_2a();
        state = STATE_2A;
        break;
      case 2:
        SWITCH_ROM(3);
        init_3a();
        state = STATE_3A;
        break;
      case 3:
        SWITCH_ROM(4);
        init_4a();
        state = STATE_4A;
        break;
    }
    clear_screen();
  }

  if (KEY_TICKED(J_B)) {
    switch (menu_item) {
      case 0:
        SWITCH_ROM(1);
        init_1b();
        state = STATE_1B;
        break;
      case 1:
        SWITCH_ROM(2);
        init_2b();
        state = STATE_2B;
        break;
      case 2:
        SWITCH_ROM(3);
        init_3b();
        state = STATE_3B;
        break;
      case 3:
        SWITCH_ROM(4);
        init_4b();
        state = STATE_4B;
        break;
    }
    clear_screen();
  }

  wait_vbl_done();
}