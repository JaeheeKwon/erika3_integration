/*
 * ShieldBuddyLed.h
 * \brief Triboard LED example function definitions.
 *
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#ifndef _SHIELDBUDDYLED_H_
#define _SHIELDBUDDYLED_H_


#define SHIELDBUDDY_LED_DIMMER_PERIOD_COUNT (50u)
#define SHIELDBUDDY_LED_INTERVAL_SECONDS    (0.05)

void ShieldBuddyLed_Init(void);
void ShieldBuddyLed_Loop_10ms(void);

#endif /* _SHIELDBUDDYLED_H_ */