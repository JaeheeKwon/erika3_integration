#include "shared.h"

void idle_hook_core1(void);
void idle_hook_core1(void)
{
  idle_hook_body();
}

TASK(TaskSlave1)
{
  while (1) {
//    WaitEvent(RemoteEvent);
//    ActivateTask(TaskSlave2);
//    led_blink(OSEE_TRIBOARD_2X5_LED_2);
//    ClearEvent(RemoteEvent);
  }
  TerminateTask();
}
