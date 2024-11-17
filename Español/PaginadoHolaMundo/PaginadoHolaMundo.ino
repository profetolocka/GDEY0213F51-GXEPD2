// Incluir las bibliotecas de GxEPD2
#include <GxEPD2_4C.h>

//Incluir fuente para el texto
#include <Fonts/FreeSans9pt7b.h>

// Definición de pines para placa adaptadora Seeed Studio
const int EINK_BUSY = D5;   // D5
const int EINK_RST  = D0;   // D0
const int EINK_DC   = D3;   // D3
const int EINK_CS   = D1;   // D1
const int EINK_SCK  = D8;  // D8 (SCK)
const int EINK_MOSI = D10;  // D10 (MOSI)


//Crea objeto del display con HEIGHT/2
GxEPD2_4C<GxEPD2_213c_GDEY0213F51, GxEPD2_213c_GDEY0213F51::HEIGHT/2> display(GxEPD2_213c_GDEY0213F51(EINK_CS, EINK_DC, EINK_RST, EINK_BUSY));

void setup() 
{
  // Inicialización del epaper
  display.init(115200);
  display.setFullWindow();
  display.fillScreen(GxEPD_WHITE);
  display.setRotation(1);
  
  //Inicializa parámetros del texto
  display.setTextColor(GxEPD_BLACK);
  display.setTextSize(2);
  display.setFont(&FreeSans9pt7b);

  // Iniciar el ciclo de paginación
  display.firstPage();
  do
  {
    //Imprime texto
    display.setCursor(0, 30);
    display.print ("Hola mundo!");

  }
  while (display.nextPage());  //Repite mientras falten páginas



}

void loop() {
  //No hace nada
}