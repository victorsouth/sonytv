
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>  /* для sei() */
#include <util/delay.h>     /* для _delay_ms() */

#include "tvcontrol.h"

#define IRLED_BIT	PA1
#define IRLED_MASK	1 << IRLED_BIT
#define IRLED_PORT	PORTA
#define IRLED_DDR	DDRA

#define LED_DDR			DDRB
#define LED_PORT		PORTB
#define LED_BIT			PB0
#define LED_MASK		1 << LED_BIT // 0b00000001

typedef unsigned char uchar;


void output_pulse(ir_pulse* pulse) {

	for (uchar bit_index = 0; bit_index < pulse->length; ++bit_index) {
		char bit = pulse->bits[bit_index];
		
		for (uchar generator = 0; generator < 24; ++generator) {
			IRLED_PORT &= ~IRLED_MASK;
			_delay_us(17);
			if (bit)
				IRLED_PORT |= IRLED_MASK;
			_delay_us(8);
		}
	}

}


void send_train(char* train) {

	for (uchar pulse_index = 0; pulse_index < sequence_12pulses_length; ++pulse_index) 
	{
		uchar pulse_code = train[pulse_index];
		ir_pulse* pulse = ir_pulses[pulse_code];
		output_pulse(pulse);
	}
}

int main() {
	IRLED_DDR |= IRLED_MASK;
	LED_DDR   |= LED_MASK;


	
	while (1) {
		send_train(mute_sound);

		LED_PORT = invert_bit(LED_PORT, LED_MASK);
		_delay_ms(3000);
	}
}














