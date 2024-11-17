// Incluir las bibliotecas necesarias
#include <GxEPD2_4C.h>

// Incluir los bitmaps de cada color
#include "gatoNegroRot.h"
#include "gatoRojoRot.h"
#include "gatoAmarilloRot.h"

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
    
  // Limpiar la pantalla
  display.fillScreen(GxEPD_WHITE); // Fondo blanco

  // Mostrar bitmaps (agregar offset en Y)
  display.drawBitmap(0, 6, gImage_gatoNegroRot, 250, 122, GxEPD_BLACK);
  display.drawBitmap(0, 6, gImage_gatoRojoRot, 250, 122, GxEPD_RED);
  display.drawBitmap(0, 6, gImage_gatoAmarilloRot, 250, 122, GxEPD_YELLOW);

  // Refrescar pantalla
  display.display ();

}

void loop() {
  //No hace nada
}