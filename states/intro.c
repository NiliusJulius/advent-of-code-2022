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
#include "..\states\5a.h"
#include "..\states\5b.h"
#include "..\states\6a.h"
#include "..\states\6b.h"
#include "..\states\7a.h"
#include "..\states\7b.h"
#include "..\states\8a.h"
#include "..\states\8b.h"
#include "..\states\9a.h"
#include "..\states\9b.h"

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
      case 4:
        SWITCH_ROM(5);
        init_5a();
        state = STATE_5A;
        break;
      case 5:
        SWITCH_ROM(6);
        init_6a();
        state = STATE_6A;
        break;
      case 6:
        SWITCH_ROM(7);
        init_7a();
        state = STATE_7A;
        break;
      case 7:
        SWITCH_ROM(8);
        init_8a();
        state = STATE_8A;
        break;
      case 8:
        SWITCH_ROM(9);
        init_9a();
        state = STATE_9A;
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
      case 4:
        SWITCH_ROM(5);
        init_5b();
        state = STATE_5B;
        break;
      case 5:
        SWITCH_ROM(6);
        init_6b();
        state = STATE_6B;
        break;
      case 6:
        SWITCH_ROM(7);
        init_7b();
        state = STATE_7B;
        break;
      case 7:
        SWITCH_ROM(8);
        init_8b();
        state = STATE_8B;
        break;
      case 8:
        SWITCH_ROM(9);
        init_9b();
        state = STATE_9B;
        break;
    }
    clear_screen();
  }

  wait_vbl_done();
}