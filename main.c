#include <gb/gb.h>
#include <gbdk/font.h>

#include "globals.h"

#include "states\intro.h"
#include "states\1a.h"
#include "states\1b.h"

#include "maps\intro_map.h"

void main() {

  // Create font.
  font_init();
  const font_t min_font = font_load(font_min);
  font_set(min_font);

  init_intro();
  state = STATE_INTRO;
  
  while (1) {
    UPDATE_KEYS();
    switch (state) {
      case STATE_INTRO:
        run_intro();
        break;
      case STATE_1A:
        run_1a();
        break;
      case STATE_1B:
        run_1b();
        break;
    }

    if (KEY_TICKED(J_START) && state != STATE_INTRO) {
      init_intro();
      state = STATE_INTRO;
    }
    
  }
}