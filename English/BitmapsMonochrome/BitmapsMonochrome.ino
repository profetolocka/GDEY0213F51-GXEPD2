// Include the necessary libraries
#include <GxEPD2_4C.h>

// Include font definitions
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

// Include the bitmap
#include "cafe120.h"

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
  
  display.setTextSize(1);
  
  // Clear the screen
  display.fillScreen(GxEPD_YELLOW); // Yellow background

  // Load bitmap
  display.drawBitmap(6, 6, gImage_cafe120, 120, 120, GxEPD_BLACK);
   
  // Print "Latte"
  display.setTextColor(GxEPD_BLACK);
  display.setCursor(145, 50);
  display.setFont(&FreeSansBold18pt7b); 
  display.print("Latte");

  // Print "-10%"
  display.setTextColor(GxEPD_RED);
  display.setCursor(130, 100);
  display.setFont(&FreeSansBold24pt7b); 
  display.print("-10%");

  // Refresh display
  display.display();
}

void loop() {
  // Does nothing
}