/**
 * \file ShieldBuddyLed.c
 * \brief Triboard LED example function definitions.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#include "Platform_Types.h"
#include "IfxPort.h"
#include "ShieldBuddyLed.h"


static uint32 ShieldBuddyLed_dimmerCount= 0;

/** \brief This function initialize the port for the Triboard Leds
 *
 */
void ShieldBuddyLed_Init(void)
{
	IfxPort_setPinModeOutput(&MODULE_P02, 6, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); 
}

void ShieldBuddyLed_Loop_10ms(void)
{
	if (ShieldBuddyLed_dimmerCount++ >= SHIELDBUDDY_LED_DIMMER_PERIOD_COUNT)
	{
		IfxPort_setPinState(&MODULE_P02, 6, IfxPort_State_toggled); 
		ShieldBuddyLed_dimmerCount= 0;
	}
}