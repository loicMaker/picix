#include "pico/stdlib.h"
/*#include "driver/lcd.h"
#include "driver/audio.h"
#include "driver/keyboard.h"*/
#include "sd_card.h"
#include "ff.h"
//#include "driver/sdcard.h"

int main() {
	/*lcd_init();
	audio_init();
  keyboard_init();*/
  sd_init_driver();
	return 0;
}