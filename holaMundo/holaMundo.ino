// Incluir las bibliotecas necesarias
#include <GxEPD2_4C.h>
#include <Fonts/FreeSans9pt7b.h>

// Definición de pines para placa ePaper
const int EINK_BUSY = D5;   // D5
const int EINK_RST  = D0;   // D0
const int EINK_DC   = D3;   // D3
const int EINK_CS   = D1;   // D1
const int EINK_SCK  = D8;  // D8 (SCK)
const int EINK_MOSI = D10;  // D10 (MOSI)


// Inicialización del display
GxEPD2_4C<GxEPD2_213c_GDEY0213F51, GxEPD2_213c_GDEY0213F51::HEIGHT> display(GxEPD2_213c_GDEY0213F51(EINK_CS, EINK_DC, EINK_RST, EINK_BUSY));

void setup() 
{
  // Inicialización del epaper
  display.init(115200);
  display.setFullWindow();
  display.fillScreen(GxEPD_WHITE);
  display.setRotation(1);
  
  display.setTextColor(GxEPD_BLACK);
  display.setTextSize(2);
  display.setFont(&FreeSans9pt7b);

  display.setCursor(0, 30);
  display.print ("Hola mundo!");
  
  display.display ();
}

void loop() {
  //No hace nada
}