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
#include "states\4a.h"
#include "states\4b.h"
#include "states\5a.h"
#include "states\5b.h"
#include "states\6a.h"
#include "states\6b.h"
#include "states\7a.h"
#include "states\7b.h"
#include "states\8a.h"
#include "states\8b.h"
#include "states\9a.h"
#include "states\9b.h"
#include "states\10a.h"
#include "states\10b.h"

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
      case STATE_4A:
        run_4a();
        break;
      case STATE_4B:
        run_4b();
        break;
      case STATE_5A:
        run_5a();
        break;
      case STATE_5B:
        run_5b();
        break;
      case STATE_6A:
        run_6a();
        break;
      case STATE_6B:
        run_6b();
        break;
      case STATE_7A:
        run_7a();
        break;
      case STATE_7B:
        run_7b();
        break;
      case STATE_8A:
        run_8a();
        break;
      case STATE_8B:
        run_8b();
        break;
      case STATE_9A:
        run_9a();
        break;
      case STATE_9B:
        run_9b();
        break;
      case STATE_10A:
        run_10a();
        break;
      case STATE_10B:
        run_10b();
        break;
    }

    if (KEY_TICKED(J_START) && state != STATE_INTRO) {
      init_intro();
      state = STATE_INTRO;
    }
    
  }
}