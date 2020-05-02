#include "buzzer.h"
#include "music.h"

void musitInit() {
  // Nothing to initialize
}

void playPewTransition() {
  for (short n = 0; n <= 4200; n++) {
    if (n % 15 == 0) {
      buzzer_set_period(n);
    }
  }
}
