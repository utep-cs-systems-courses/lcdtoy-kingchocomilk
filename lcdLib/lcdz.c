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
  u_char width = screenWidth, height = screenHeight;
  u_char j;
  clearScreen(COLOR_BLUE);

  // Draws a diagnol line.
  for (j = 0; j <= 30; j++){
    //drawPixel(j, j, COLOR_BLACK); // Draw line top-left to bottom-right
    //drawPixel(30 - j, j, COLOR_BLACK); // Draw line top-right to bottom-left
    //drawPixel(j, 15, COLOR_BLACK); // Draw line left to right
    //drawPixel(15, j, COLOR_BLACK); // Draw line top to bottom

    drawPixel(30, j, COLOR_BLACK); // TRIANGLE
    drawPixel(j, 30, COLOR_BLACK);
    drawPixel(30 - j, j, COLOR_BLACK);
  }

  //  drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  //  fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  
}
