#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "drawUnique.h"
#include "p2switches.h"

int main() {
  configureClocks();
  lcd_init();
  buzzer_init();
  p2sw_init(15);
  or_sr(0x18);
}
