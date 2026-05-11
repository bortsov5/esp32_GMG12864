#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

/*
15  //si
2   //scl
5   //rs
23  //RSE
13  //cs
*/

#define PIN_SI   15  // Data (MOSI)
#define PIN_SCL  2   // Clock (SCK)
#define PIN_RS   5   // Register Select (DC)
#define PIN_RSE  23  // Reset (RST)
#define PIN_CS   13  // Chip Select


U8G2_ST7565_ERC12864_1_4W_SW_SPI u8g2(
  U8G2_R0,           // Rotation
  PIN_SCL,           // Clock
  PIN_SI,            // Data
  PIN_CS,            // Chip Select
  PIN_RS,            // Data/Command
  PIN_RSE            // Reset
);



void setup(void) {
  u8g2.begin();
  u8g2.enableUTF8Print();  
   u8g2.setContrast(10);
  Serial.begin(115200);

   u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_5x7_t_cyrillic);
    u8g2.drawUTF8(0, 10, "GPS Навигатор");
    u8g2.drawUTF8(0, 30, "Версия 1.0");
    u8g2.drawUTF8(0, 50, "Симуляция маршрута");
  } while (u8g2.nextPage());
  
  Serial.println("Display ready!");

  delay(2000);


  // Тестовый паттерн
  u8g2.firstPage();
  do {
    u8g2.drawBox(0, 0, 128, 64);  // Заливка всего экрана
  } while (u8g2.nextPage());
  
  delay(2000);
  
  u8g2.firstPage();
  do {
    u8g2.drawFrame(10, 10, 108, 44);  // Рамка
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(20, 30, "Test Pattern");
  } while (u8g2.nextPage());

}

void loop(void) {
 

}
