/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight, x_offset = 50, y_offset = 25;
  u_char j,i,k, width_start, width_end;
  clearScreen(COLOR_BLUE);

  // Draws a diagnol line.
  /*
  for (j = 0; j <= 30; j++){
    width_start = 0;
    width_end = j;
    for (i = 0; i <= width_end; i++){
      if (j >= 15) {
	drawPixel(x_offset + i, y_offset + j, COLOR_BLACK);
	drawPixel(x_offset - i, y_offset + j, COLOR_BLACK); 
      }
    }
    }*/

  for (j = 0; j <= 15; j++) {
    width_start = 15 - j;
    width_end = 15;
    for (i = width_start; i <= width_end; i++){
      drawPixel(20 + i, 20 + j, COLOR_BLACK);
      drawPixel(20 + i, 20 - j, COLOR_BLACK);
      drawPixel(20 - i, 20 + j, COLOR_BLACK);
      drawPixel(20 - i, 20 - j, COLOR_BLACK);
      
    }
  }

  //  drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  //  fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  
}
