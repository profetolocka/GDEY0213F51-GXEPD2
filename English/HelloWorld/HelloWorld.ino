// Include the GxEPD2 libraries
#include <GxEPD2_4C.h>

// Include font for the text
#include <Fonts/FreeSans9pt7b.h>

// Define pins for the Seeed Studio adapter board
const int EINK_BUSY = D5;   // D5
const int EINK_RST  = D0;   // D0
const int EINK_DC   = D3;   // D3
const int EINK_CS   = D1;   // D1
const int EINK_SCK  = D8;  // D8 (SCK)
const int EINK_MOSI = D10;  // D10 (MOSI)

// Create display object
GxEPD2_4C<GxEPD2_213c_GDEY0213F51, GxEPD2_213c_GDEY0213F51::HEIGHT> 
 display(GxEPD2_213c_GDEY0213F51(EINK_CS, EINK_DC, EINK_RST, EINK_BUSY));

void setup() {
  // Initialize the e-paper
  display.init(115200);
  display.setFullWindow();
  display.fillScreen(GxEPD_WHITE);
  display.setRotation(1);
  
  // Initialize text parameters
  display.setTextColor(GxEPD_BLACK);
  display.setTextSize(2);
  display.setFont(&FreeSans9pt7b);

  // Print text
  display.setCursor(0, 30);
  display.print ("Hello world!");
  
  // Update ePaper
  display.display ();
}

void loop() {
  // Does nothing
}