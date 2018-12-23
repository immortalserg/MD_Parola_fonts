#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "5bite_rus.h" // подключаем внешний шрифт
#define HARDWARE_TYPE MD_MAX72XX::ICSTATION_HW
#define MAX_DEVICES 4 // количество модулей
#define CS_PIN    4 // CS SPI
// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
void setup()
{
  P.begin();
  P.setFont(_5bite_rus);
  P.displayText("СЪЕШЬ ЕЩЕ ЭТИХ МАЛЕНЬКИХ БУЛОЧЕК И ВЫПЕЙ ЧАЮ, съешь еще этих маленьких булочек и выпей чаю", PA_CENTER , 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}
void loop()
{
  if (P.displayAnimate())
  {
    P.displayReset();
  }
}
