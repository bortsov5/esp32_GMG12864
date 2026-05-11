
# lib/U8g2  

<img src="img\photo_2026-05-11_11-04-59.jpg" alt="" width="600">
<img src="img\photo_2026-05-11_11-05-29.jpg" alt="" width="600">
<img src="img\photo_2026-05-11_11-05-54.jpg" alt="" width="600">
<img src="img\photo_2026-05-11_11-05-59.jpg" alt="" width="600">


U8G2_ST7565_ERC12864_1_4W_HW_SPI u8g2(
  U8G2_R0,           // Rotation
  PIN_CS,            // Chip Select
  PIN_RS,            // Data/Command
  PIN_RSE            // Reset
);

void setup(void)
{

  SPI.begin(PIN_SCL, -1, PIN_SI, PIN_CS);  // SCK, MISO, MOSI, CS
  u8g2.begin();
  ...
