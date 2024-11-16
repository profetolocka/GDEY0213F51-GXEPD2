// Incluir las bibliotecas necesarias
#include <GxEPD2_4C.h>

//Incluir las definiciones de las fuentes
#include <Fonts/FreeSansBold18pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

// Incluir el bitmap
#include "cafe120.h"

// Definición de pines para placa adaptadora de Seeed Studio
const int EINK_BUSY = D5;   // D5
const int EINK_RST  = D0;   // D0
const int EINK_DC   = D3;   // D3
const int EINK_CS   = D1;   // D1
const int EINK_SCK  = D8;  // D8 (SCK)
const int EINK_MOSI = D10;  // D10 (MOSI)

// Crea el objeto asociado a la pantalla
GxEPD2_4C<GxEPD2_213c_GDEY0213F51, GxEPD2_213c_GDEY0213F51::HEIGHT> display(GxEPD2_213c_GDEY0213F51(EINK_CS, EINK_DC, EINK_RST, EINK_BUSY));

void setup() 
{
  // Inicialización del epaper
  display.init(115200);
  display.setFullWindow();
  display.setRotation(1);
  
  display.setTextSize(1);
  
  // Limpiar la pantalla
  display.fillScreen(GxEPD_YELLOW); // Fondo amarillo

  // Cargar bitmap
  display.drawBitmap(6, 6, gImage_cafe120, 120, 120, GxEPD_BLACK);
   
  // Imprimir "Latte"
  display.setTextColor(GxEPD_BLACK);
  display.setCursor(145, 50);
  display.setFont(&FreeSansBold18pt7b); 
  display.print ("Latte");

  // Imprimir "-10%"
  display.setTextColor(GxEPD_RED);
  display.setCursor(130, 100);
  display.setFont(&FreeSansBold24pt7b); 
  display.print ("-10%");

  // Refrescar pantalla
  display.display ();

}

void loop() {
  //No hace nada
}