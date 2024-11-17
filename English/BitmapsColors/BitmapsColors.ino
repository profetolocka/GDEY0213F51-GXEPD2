// Include the necessary libraries
#include <GxEPD2_4C.h>

// Include the bitmaps of each color
#include "CatBlack.h"
#include "CatRed.h"
#include "CatYellow.h"

// Pin definitions for Seeed Studio adapter board
const int EINK_BUSY = D5;   // D5
const int EINK_RST  = D0;   // D0
const int EINK_DC   = D3;   // D3
const int EINK_CS   = D1;   // D1
const int EINK_SCK  = D8;   // D8 (SCK)
const int EINK_MOSI = D10;  // D10 (MOSI)

// Create the object associated with the display
GxEPD2_4C<GxEPD2_213c_GDEY0213F51, GxEPD2_213c_GDEY0213F51::HEIGHT> display(GxEPD2_213c_GDEY0213F51(EINK_CS, EINK_DC, EINK_RST, EINK_BUSY));

void setup() 
{
  // Initialize the ePaper display
  display.init(115200);
  display.setFullWindow();
  display.setRotation(1);
    
  // Clear the screen
  display.fillScreen(GxEPD_WHITE); // White background

  // Display bitmaps (add offset in Y)
  display.drawBitmap(0, 6, gImage_gatoNegroRot, 250, 122, GxEPD_BLACK);
  display.drawBitmap(0, 6, gImage_gatoRojoRot, 250, 122, GxEPD_RED);
  display.drawBitmap(0, 6, gImage_gatoAmarilloRot, 250, 122, GxEPD_YELLOW);

  // Refresh display
  display.display();
}

void loop() {
  // Does nothing
}