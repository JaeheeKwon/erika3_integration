/**
 * \file master.c
 * \brief OS task definitions.
 *
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#include "os.h"
#include "IfxStm.h"
#include "IfxStm_reg.h"
#include "ShieldBuddyLed.h"
#include "shared.h"

#define OSEE_TC2YX_OUTPUT_PUSH_PULL_GP	0x10U

void Ifx_OSTask_initBlinkyLedFunction (void);

TASK(IFX_OSTASK_INIT)
{
    /*Add your initialization code here*/
    ActivateTask(IFX_OSTASK_BACKGROUND);

/*  Alarms are Auto started with the same parameters as below. Code below is not necessary.
 * You could also implement this if you want to change the parameters of alarms
 */
#if 0	
    SetRelAlarm(IFX_OSTASK_ALARM_1MS,0,1);
    SetRelAlarm(IFX_OSTASK_ALARM_5MS,2,5);
    SetRelAlarm(IFX_OSTASK_ALARM_10MS,5,10);
    SetRelAlarm(IFX_OSTASK_ALARM_20MS,10,20);
    SetRelAlarm(IFX_OSTASK_ALARM_50MS,25,50);
    SetRelAlarm(IFX_OSTASK_ALARM_100MS,50,100);
#endif
    Ifx_OSTask_initBlinkyLedFunction();
    ShieldBuddyLed_Init(); //TODO : Application call
    ActivateTask(IFX_OSTASK_EVENT1);
    TerminateTask();
}

uint32 BlinkLedIsrCnt = 0;
/*Define an ISR category 2 to trigger events.
 * Category 2 ISR needed here because of the call restriction
 * with SetEvent API*/
ISR(Ifx_OSTask_BlinkLedIsr)
{
    uint32 stmTicks;
    stmTicks= (uint32)(SHIELDBUDDY_LED_INTERVAL_SECONDS * IfxStm_getFrequency (&MODULE_STM0));
    IfxStm_updateCompare (&MODULE_STM0, IfxStm_Comparator_1, IfxStm_getCompare (&MODULE_STM0, IfxStm_Comparator_1) + stmTicks);
    SetEvent (IFX_OSTASK_EVENT1, 1);
    BlinkLedIsrCnt++; 
}

/*Initialize theSTM 0 and set the comparator 1 to trigger an interrupt
 * which will in turn trigger event 1*/
void Ifx_OSTask_initBlinkyLedFunction (void)
{
    IfxStm_CompareConfig stmCompareConfig;

    //Call the constructor of configuration
    IfxStm_initCompareConfig (&stmCompareConfig);
    //Select comparator 1
    stmCompareConfig.comparator=IfxStm_Comparator_1;
    stmCompareConfig.comparatorInterrupt=IfxStm_ComparatorInterrupt_ir1;
    //Modify only the number of ticks and enable the trigger output
    stmCompareConfig.ticks = 100;   /*Interrupt after 100 ticks from now */
    stmCompareConfig.triggerPriority = 11;
    stmCompareConfig.typeOfService= IfxSrc_Tos_cpu0;

    //Now Compare functionality is initialized
    IfxStm_initCompare (&MODULE_STM0, &stmCompareConfig);
}

uint32 Ifx_OSTask_Event1_Count;
TASK(IFX_OSTASK_EVENT1)
{
    while (1)
    {
        ClearEvent ( 1 );
        WaitEvent ( 1 );
        {
            /*Call your event 1 related functions here*/
            //ShieldBuddyLed_sweepGlow(); //TODO : Application call
        }
    }
    TerminateTask();
}

uint32 Ifx_OSTask_Event2_Count;
TASK(IFX_OSTASK_EVENT2)
{
    Ifx_OSTask_Event2_Count++;
    {
        /*Call your event 2 related functions here*/
    }
    TerminateTask();
}

uint32 Ifx_OSTask_Event3_Count;
TASK(IFX_OSTASK_EVENT3)
{
    Ifx_OSTask_Event3_Count++;
    {
        /*Call your event 3 related functions here*/
    }
    TerminateTask();
}

uint32 Ifx_OSTask_1ms_Count;
TASK(IFX_OSTASK_1MS)
{
    Ifx_OSTask_1ms_Count++;
    {
        /*Call your 1ms functions here*/
    }
    TerminateTask();
}

uint32 Ifx_OSTask_5ms_Count;
TASK(IFX_OSTASK_5MS)
{
    Ifx_OSTask_5ms_Count++;
    {
        /*Call your 5ms functions here*/
    }
    TerminateTask();
}

uint32 Ifx_OSTask_10ms_Count;
TASK(IFX_OSTASK_10MS)
{
    Ifx_OSTask_10ms_Count++;
    {
        /*Call your 10ms functions here*/
        ShieldBuddyLed_Loop_10ms();
    }
    TerminateTask();
}

uint32 Ifx_OSTask_20ms_Count;
TASK(IFX_OSTASK_20MS)
{
    Ifx_OSTask_20ms_Count++;
    {
        /*Call your 20ms functions here*/
    }
    TerminateTask();
}

uint32 Ifx_OSTask_50ms_Count;
TASK(IFX_OSTASK_50MS)
{
    Ifx_OSTask_50ms_Count++;
    {
        /*Call your 100ms functions here*/
    }
    TerminateTask();
}

uint32 Ifx_OSTask_100ms_Count;
TASK(IFX_OSTASK_100MS)
{
    Ifx_OSTask_100ms_Count++;
    {
        /*Call your 100ms functions here*/
    }
    TerminateTask();
}

uint32 Ifx_OSTask_Background_Count;
TASK(IFX_OSTASK_BACKGROUND)
{
    Ifx_OSTask_Background_Count++;
    /*Add your code here*/

    while(1)
    {
    }
    TerminateTask();
}

void idle_hook_core0(void)
{
    idle_hook_body();
}

uint32 myErrorCounter = 0;
void ErrorHook(StatusType Error)
{
  (void)Error;
  ++myErrorCounter;
}

