// Incluir las bibliotecas necesarias
#include <GxEPD2_4C.h>

//Incluir las definiciones de las fuentes
#include <Fonts/FreeMonoBold12pt7b.h>


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
  
  // Definir el centro y el radio del círculo
  int centerX = 60;
  int centerY = 80;
  int radius = 40; // Radio es la mitad del diámetro (80/2)

  // Limpiar la pantalla
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_YELLOW); // Fondo blanco

    //1.Gráfico de tortas
    
    // Dibujar el círculo relleno de rojo
    display.fillCircle(centerX, centerY, radius, GxEPD_RED);

    // Dibujar un punto en el centro
    //display.drawPixel(centerX, centerY, GxEPD_WHITE);

    // Calcular los ángulos para las secciones del gráfico
    float angle1 = 0;
    float angle2 = 144; // 40% de 360 grados (0.4 * 360)
    float angle3 = 252; // 144 + 108 (30% de 360 grados)

    // Convertir grados a radianes
    float angle1_rad = angle1 * PI / 180;
    float angle2_rad = angle2 * PI / 180;
    float angle3_rad = angle3 * PI / 180;

    // Calcular las coordenadas de los puntos en el borde del círculo
    int x1 = centerX + radius * cos(angle1_rad);
    int y1 = centerY + radius * sin(angle1_rad);

    int x2 = centerX + radius * cos(angle2_rad);
    int y2 = centerY + radius * sin(angle2_rad);

    int x3 = centerX + radius * cos(angle3_rad);
    int y3 = centerY + radius * sin(angle3_rad);

    // Dibujar las líneas desde el centro hasta el borde
    display.drawLine(centerX, centerY, x1, y1, GxEPD_WHITE);
    display.drawLine(centerX, centerY, x2, y2, GxEPD_WHITE);
    display.drawLine(centerX, centerY, x3, y3, GxEPD_WHITE);

    //2.Gráfico de barras

    display.drawLine (120,110, 220,110, GxEPD_BLACK);
    display.drawLine (120,110, 120, 40, GxEPD_BLACK);

    display.fillRect(130, 110-50, 20, 50, GxEPD_RED);
    display.fillRect(155, 110-50, 20, 40, GxEPD_RED);
    display.fillRect(180, 110-50, 20, 45, GxEPD_RED);


    


    
    display.setTextColor(GxEPD_BLACK);

    display.setCursor(15, 20);
    display.setFont(&FreeMonoBold12pt7b); 
    display.print ("ACME Corporation");

  } while (display.nextPage());

}

void loop() {
  //No hace nada
}