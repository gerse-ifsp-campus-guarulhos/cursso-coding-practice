#include <Arduino.h>
#include <hardware.h>

void setup( void ) {
	pinMode( BT1_PIN,		INPUT_PULLUP		);
	pinMode( BT2_PIN,		INPUT_PULLUP		);
	pinMode( BT3_PIN,		INPUT_PULLUP		);
	pinMode( POT_PIN,		INPUT			);
	pinMode( LCD_PIN_LED_A,		OUTPUT			);
	pinMode( LCD_PIN_LED_B,		OUTPUT			);
	pinMode( LCD_PIN_LED_C,		OUTPUT			);
	pinMode( LCD_PIN_LED_D,		OUTPUT			);
	pinMode( LCD_PIN_LED_E,		OUTPUT			);
	pinMode( LCD_PIN_LED_F,		OUTPUT			);
	pinMode( LCD_PIN_LED_G,		OUTPUT			);

	digitalWrite( LCD_PIN_LED_A,	LOW			);
	digitalWrite( LCD_PIN_LED_B,	LOW			);
	digitalWrite( LCD_PIN_LED_C,	LOW			);
	digitalWrite( LCD_PIN_LED_D,	LOW			);
	digitalWrite( LCD_PIN_LED_E,	LOW			);
	digitalWrite( LCD_PIN_LED_F,	LOW			);
	digitalWrite( LCD_PIN_LED_G,	LOW			);
}

void loop( void ) {

}