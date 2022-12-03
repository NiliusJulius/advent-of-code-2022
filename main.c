#include <gb/gb.h>
#include <gbdk/font.h>

#include "globals.h"

#include "states\intro.h"
#include "states\1a.h"
#include "states\1b.h"
#include "states\2a.h"
#include "states\2b.h"
#include "states\3a.h"
#include "states\3b.h"

#include "maps\intro_map.h"

void main() {

  // Create font.
  font_init();
  const font_t spect_font = font_load(font_spect);
  font_set(spect_font);

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
      case STATE_2A:
        run_2a();
        break;
      case STATE_2B:
        run_2b();
        break;
      case STATE_3A:
        run_3a();
        break;
      case STATE_3B:
        run_3b();
        break;
    }

    if (KEY_TICKED(J_START) && state != STATE_INTRO) {
      init_intro();
      state = STATE_INTRO;
    }
    
  }
}