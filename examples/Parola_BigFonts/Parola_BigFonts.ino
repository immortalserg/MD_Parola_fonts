#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "BigFontRus7.h"
#define HARDWARE_TYPE MD_MAX72XX::ICSTATION_HW
#define MAX_ZONES 2 // количество зон (в данном случае строк)
#define ZONE_SIZE 4 // количество матриц в одной зоне (в данном случае в строке )
#define MAX_DEVICES (MAX_ZONES * ZONE_SIZE)
#define ZONE_UPPER 1 // номер зоны для верхней строки
#define ZONE_LOWER 0 // номер зоны для нижней строки
#define CS_PIN 4 // номер пина CS SPI
// выводимый текст
char* text = "СЪЕШЬ ЕЩЕ ЭТИХ МАЛЕНЬКИХ БУЛОЧЕК И ВЫПЕЙ ЧАЮ, съешь еще этих маленьких булочек и выпей чаю";
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
void setup()
{ 
  P.begin(MAX_ZONES);
  P.setZone(ZONE_UPPER, ZONE_SIZE, MAX_DEVICES-1);
  P.setFont(ZONE_UPPER, _BigFontRus7Upper); // название шрифта для верхней части символов
  P.setZone(ZONE_LOWER, 0, ZONE_SIZE - 1);
  P.setFont(ZONE_LOWER, _BigFontRus7Lower); // название шрифта для нижней части символов
  P.setCharSpacing(P.getCharSpacing()*2);// двойной интервал между символами
}
void loop() 
{  
     if (P.displayAnimate()) 
        {
         P.displayZoneText(ZONE_UPPER, text, PA_CENTER, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
         P.displayZoneText(ZONE_LOWER, text, PA_CENTER, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
         P.synchZoneStart(); 
        } 
}
