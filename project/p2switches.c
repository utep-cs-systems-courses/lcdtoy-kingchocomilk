#ifndef p2_switches
#define p2_switches

#include <msp430.h>
#include "p2switches.h"
#include "drawUnique.h"
#include "music.h"
#include "buzzer.h"

static unsigned char switch_mask;
static unsigned char switches_last_reported;
static unsigned char switches_current, switch1_state_down, switch2_state_down,
  switch3_state_down, switch4_state_down, switch_state_changed;

static void
switch_update_interrupt_sense()
{
  switches_current = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (switches_current);  /* if switch up, sense down */
  P2IES &= (switches_current | ~SWITCHES); /* if switch down, sense up */
}

void 
p2sw_init(unsigned char mask)
{
  /* Decided to go with older switch system. */
  P2REN |= SWITCHES;    /* enables resistors for switches */
  P2IE = SWITCHES;      /* enable interrupts from switches */
  P2OUT |= SWITCHES;    /* pull-ups for switches */
  P2DIR &= ~SWITCHES;   /* set switches' bits for input */

  switch_update_interrupt_sense();
}

/* Returns a word where:
 * the high-order byte is the buttons that have changed,
 * the low-order byte is the current state of the buttons
 */
unsigned int 
p2sw_read() {
  return switches_current;
}

void switch_interrupt_handler() {
  if (switch_state_changed) {
    char p2val = p2sw_read(); // The state of the switches is here with all buttons.
    switch1_state_down = (p2val & SW1) ? 0 : 1;
    switch2_state_down = (p2val & SW2) ? 0 : 1;
    switch3_state_down = (p2val & SW3) ? 0 : 1;
    switch4_state_down = (p2val & SW4) ? 0 : 1;

    if (switch1_state_down) {
      // Play our tone for loading screen
      buzzer_set_period(2000);
      // Draw our unique picture
      drawPicture1(40, 40);
      // Silence the tone again, done loading.
      buzzer_set_period(Z0);
    }
    else if (switch2_state_down) {
      buzzer_set_period(2000);
      drawPicture2(40, 40);
      buzzer_set_period(Z0);
    }
    else if (switch3_state_down) {
      buzzer_set_period(2000);
      drawPicture3(40, 40);
      buzzer_set_period(Z0);
    }
    else if (switch4_state_down) {
      buzzer_set_period(2000);
      drawPicture4(40, 40);
      buzzer_set_period(Z0);
    }

    switch_state_changed = 0;
  }
}

/* Switch on P2 (S1) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {  /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;	/* clear pending sw interrupts */
    switch_state_changed = 1; // Update and notify the rest of code that the state changed
    switch_update_interrupt_sense();
    switch_interrupt_handler();
  }
}
#endif
