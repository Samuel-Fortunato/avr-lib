#pragma once
#include <stdint.h>

#define PWM_OUT_A 6
#define PWM_OUT_B 5

typedef enum { PWM_MODE_FAST = 0, PWM_MODE_PHASE_COR = 1 } PWM_Mode_t;

typedef enum { PWM_CH_A = 1, PWM_CH_B = 2 , PWM_CH_AB = 3} PWM_Channels_t;

typedef enum {
	CLK_OFF,
	CLK_NO_DIV,
	CLK_DIV_8,
	CLK_DIV_64,
	CLK_DIV_256,
	CLK_DIV_1024,
	CLK_EXT_FALL,
	CLK_EXT_RISE
} PWM_Clock_t;

typedef struct {
	PWM_Mode_t mode : 1;					// 1 - Phase Correct PWM / 0 - Fast PWM
	PWM_Channels_t channels : 2;		// 1 - Channel A and B / 0 - Channel A
	PWM_Clock_t clock : 3;				// Clock Speed - Check Datasheet
} PWM_Config_t;

void pwm_init(PWM_Config_t);

void pwm_setA(uint8_t);
void pwm_setB(uint8_t);
