/**
 * \file main.c
 * \brief
 *
 *                                 IMPORTANT NOTICE
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#include "os.h"

int main(void)
{
  StatusType  status;
  AppModeType mode;
  CoreIdType  core_id = GetCoreID();

  if (core_id == OS_CORE_ID_MASTER) {
    StartCore(OS_CORE_ID_1, &status);
    StartCore(OS_CORE_ID_2, &status);
    mode = OSDEFAULTAPPMODE;
  } else {
    mode = DONOTCARE;
  }
  StartOS(mode);
}
