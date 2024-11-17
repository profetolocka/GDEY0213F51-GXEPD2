// Incluir las bibliotecas necesarias
#include <GxEPD2_4C.h>

//Incluir las definiciones de las fuentes
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>

// Incluir bitmaps
#include "ReunionesNegro.h"
#include "ReunionesAmarillo.h"


// Definición de pines para placa adaptadora de Seeed Studio
const int EINK_BUSY = D5;   // D5
const int EINK_RST  = D0;   // D0
const int EINK_DC   = D3;   // D3
const int EINK_CS   = D1;   // D1
const int EINK_SCK  = D8;  // D8 (SCK)
const int EINK_MOSI = D10;  // D10 (MOSI)

// Crea el objeto asociado a la pantalla
GxEPD2_4C<GxEPD2_213c_GDEY0213F51, GxEPD2_213c_GDEY0213F51::HEIGHT/2> display(GxEPD2_213c_GDEY0213F51(EINK_CS, EINK_DC, EINK_RST, EINK_BUSY));

void setup() 
{
  // Inicialización del epaper
  display.init(115200);
  display.setFullWindow();
  display.setRotation(1);
  
  display.setTextSize(1);

  // Start the pagination cycle
  display.firstPage();
  do
  {
    // Limpiar la pantalla
    display.fillScreen(GxEPD_WHITE); // Fondo blanco

    // Cargar bitmaps
    display.drawBitmap(130, 6, gImage_ReunionesAmarillo, 120, 120, GxEPD_YELLOW);
    display.drawBitmap(130, 6, gImage_ReunionesNegro, 120, 120, GxEPD_BLACK);

    // Imprimir "Room 1"
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(12, 40);
    display.setFont(&FreeSansBold12pt7b); 
    display.print ("ROOM 1");

    // Imprimir "Busy"
    display.setTextColor(GxEPD_RED);
    display.setCursor(10, 100);
    display.setFont(&FreeSansBold18pt7b); 
    display.print ("BUSY");
  }
  while (display.nextPage());  // Repeat while there are pages left
}

void loop() {
  //No hace nada
}