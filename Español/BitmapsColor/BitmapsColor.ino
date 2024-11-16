// Incluir las bibliotecas necesarias
#include <GxEPD2_4C.h>

//Incluir las definiciones de las fuentes
#include <Fonts/FreeMonoBold12pt7b.h>

// Incluir el bitmap
#include "gatoNegroRotado.h"
#include "gatoRojoRotado.h"
#include "gatoAmarilloRotado.h"

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
  display.fillScreen(GxEPD_WHITE);
  display.setRotation(1);
  
  display.setTextSize(1);
  
  // Limpiar la pantalla
  display.fillScreen(GxEPD_WHITE); // Fondo blanco

  // Cargar bitmap
  display.drawBitmap(0, 0, gImage_gatoNegroRotado, 250, 128, GxEPD_BLACK);
  display.drawBitmap(0, 0, gImage_gatoRojoRotado, 250, 128, GxEPD_RED);
  display.drawBitmap(0, 0, gImage_gatoAmarilloRotado, 250, 128, GxEPD_YELLOW);
   
  // Configuración del texto
  display.setTextColor(GxEPD_BLACK);
  display.setCursor(15, 20);
  display.setFont(&FreeMonoBold12pt7b); 

  // Imprimir texto
  display.print ("ACME Corporation");

  // Refrescar pantalla
  display.display ();

}

void loop() {
  //No hace nada
}