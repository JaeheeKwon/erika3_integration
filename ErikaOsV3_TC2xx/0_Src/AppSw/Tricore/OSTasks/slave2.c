#include "shared.h"

void idle_hook_core2(void);
void idle_hook_core2(void)
{
  idle_hook_body();
}

TASK(TaskSlave2)
{
//  led_blink(OSEE_TRIBOARD_2X5_LED_3);
//  SetRelAlarm(AlarmSlave2RemoteCPU0, 50, 0);
  TerminateTask();
}

