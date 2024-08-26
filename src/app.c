/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include "stdio.h"

#include "sl_sleeptimer.h"
#include "sl_simple_led.h"
#include "sl_simple_led_instances.h"

void my_timer_callback(sl_sleeptimer_timer_handle_t *handle, void *data)
{
  //Code executed when the timer expire.
  sl_simple_led_toggle(SL_SIMPLE_LED_INSTANCE(0)->context);
}

int start_timer(void)
{
  sl_status_t status;
  static sl_sleeptimer_timer_handle_t my_timer;
  uint32_t timer_timeout = 500;

  // We assume the sleeptimer is initialized properly
  status = sl_sleeptimer_start_periodic_timer_ms(&my_timer,
                                                  timer_timeout,
                                                  my_timer_callback,
                                                  (void *)NULL,
                                                  0,
                                                  0);

  if(status != SL_STATUS_OK) {
    return -1;
  }
  return 1;
}

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  int ret = start_timer();
  printf("Hello World Blinky : %d !\n", ret);
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
}
