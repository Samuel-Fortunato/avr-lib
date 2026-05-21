#include "pwm/pwm.h"
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>


static uint8_t initialized = 0;


void pwm_init(PWM_Config_t config) {
	TCCR0A |= _BV(WGM00);

	if (config.mode == PWM_MODE_PHASE_COR) {
		TCCR0A |= _BV(WGM00);
	}
	if (config.channels & PWM_CH_A) {
		DDRD |= _BV(PWM_OUT_A);
		TCCR0A |= (_BV(COM0A1));
	}
	if (config.channels & PWM_CH_B) {
		DDRD |= _BV(PWM_OUT_B);
		TCCR0A |= (_BV(COM0B1));
	}

	TCCR0B = (TCCR0B & ~(0b111)) | config.clock;
}

void pwm_setA(uint8_t value) {
	// if (!value) {
	// 	TCCR0A &= ~(_BV(COM0A1));
	// 	return;
	// }
	// TCCR0A |= _BV(COM0A1);
	OCR0A = value;
};

void pwm_setB(uint8_t value) {
	// if (!value) {
	// 	TCCR0A &= ~(_BV(COM0B1));
	// 	return;
	// }
	// TCCR0A |= _BV(COM0B1);
	OCR0B = value;
};
