#include "drawUnique.h"
#include "lcddraw.h"
#include "lcdutils.h"


// Draws a house
void drawPicture1(u_char houseWidth, u_char houseHeight) {
  // Change background.
  clearScreen(COLOR_GREEN);
  // Draw the bulk of the house
  fillRectangle((screenWidth/2) - (houseWidth/2), (screenHeight/2) - (houseHeight/2)
		, houseWidth, houseHeight, COLOR_BROWN);

  // Draw the roof
  u_char i, j, rStart, rEnd;
  for (j = 0; j <= (houseHeight/2); j++) {
    rStart = 0;
    rEnd = j*2;
    for (i = 0; i <= rEnd; i++) {
      drawPixel((screenWidth/2) + i, (screenHeight/2) + j - (houseHeight), COLOR_GRAY);
      drawPixel((screenWidth/2) - i, (screenHeight/2) + j - (houseHeight), COLOR_GRAY);
    }
  }

  // Draw Door
  fillRectangle((screenWidth/2) - (houseWidth/4), (screenHeight/2),
		 (houseWidth/4), (houseHeight/2), COLOR_BLACK);

  
}

// Draws a construction crane
void drawPicture2(u_char craneWidth, u_char craneHeight) {
  clearScreen(COLOR_ORANGE);
  // Draw the pillar on left
  fillRectangle((screenWidth/2) - (craneWidth/2), (screenHeight/2) - (craneHeight/2),
		(craneWidth/8), (craneHeight), COLOR_RED);

  // Draw support anchor
  u_char i, j, rStart, rEnd;
  for (j = 0; j <= (craneHeight/8); j++) {
    rStart = 0;
    rEnd = (craneWidth/2) - j;
    for (i = rStart; i <= rEnd; i++) {
      drawPixel((screenWidth/2) - (craneWidth/2) + i, (screenHeight/2) - (craneHeight/2) + j,
		COLOR_RED);
    }
  }
  // Draw cable and box
  i = 0;
  for (j = 0; j <= (craneHeight/2); j++) {
    drawPixel((screenWidth/2) + i, (screenHeight/2) - (craneHeight/2) + j, COLOR_BLACK);
  }
  fillRectangle((screenWidth/2) - (craneWidth/6) + 3, (screenHeight/2) - (craneHeight/6)+3
		, (craneWidth/6), (craneHeight/6), COLOR_BROWN);
}

// Draw cross with scripture
void drawPicture3(u_char crossWidth, u_char crossHeight) {
  clearScreen(COLOR_BLUE);
  drawString5x7(0, 0, "John 3:16", COLOR_WHITE, COLOR_BLUE);
  fillRectangle((screenWidth/2) - (crossWidth/6), (screenHeight/2) - (crossHeight/2),
		(crossWidth/6), (crossHeight), COLOR_YELLOW);
  fillRectangle((screenWidth/2) - (crossWidth/3), (screenHeight/2) - (crossHeight/3),
		(crossWidth/2), (crossHeight/6), COLOR_YELLOW);
  
}

// Draw UTEP!
void drawPicture4(u_char pickWidth, u_char pickHeight) {
  
  clearScreen(COLOR_ORANGE);
  drawString8x12(10, 5, "Go Miners!", COLOR_WHITE, COLOR_ORANGE);

  // Draw staff
  fillRectangle((screenWidth/2) - (pickWidth/8), (screenHeight/2) - (pickHeight/2),
		(pickWidth/8), (pickHeight), COLOR_BROWN);

  // Draw Holding Part
  fillRectangle((screenWidth/2) - (pickWidth/6), (screenHeight/2) - (3*(pickHeight/8)),
		(pickWidth/6),(pickHeight/6), COLOR_GRAY);

  // Draw back side of pick
  int i,j, rStart, rEnd;
  for (j = 0; j <= (pickHeight/7); j++) {
    rStart = 0;
    rEnd = j * ((pickWidth/2) / (pickHeight/7));
    for (i = 0; i <= rEnd; i++) {
      drawPixel((screenWidth/2) - (pickWidth/6) - i, (screenHeight/2) - (3*(pickHeight/8))+1 + j, COLOR_GRAY);
    }
  }
  // Draw front side of pick
  for (j = 0; j <= (pickHeight/7); j++) {
    rStart = 0;
    rEnd = j * ((pickWidth/2) / (pickHeight/7));
    for (i = 0; i <= rEnd; i++) {
      drawPixel((screenWidth/2) + i, (screenHeight/2) - (3*(pickHeight/8))+1 + j, COLOR_GRAY);
    }
  }
}
