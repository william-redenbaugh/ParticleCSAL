#ifndef _OS_TIMER_H
#define _OS_TIMER_H

#include "CSAL_SHARED/os_error.h"

typedef void *(timer_cb_func_t)(void);

typedef struct os_timer_t{
    Timer *timer;
    timer_cb_func_t timer_cb;
}os_timer_t;


/**
 * @brief Initializes a timer module 
 * @param os_timer_t *pointer to timer structure
 * @param timer_cb_func_t timer callback
 * @param uint32_t timer_period interval of timer
 * @returns return status
*/
int os_timer_init(os_timer_t *timer, timer_cb_func_t timer_cb, uint32_t timer_period);

/**
 * @brief Starts the timer to run perioidcally
 * @param os_timer_t *pointer to timer structure
 * @returns return status
*/
int os_timer_start_periodic(os_timer_t *timer);

/**
 * @brief Starts the timer to run once
 * @param os_timer_t *pointer to timer structure
 * @returns return status
*/
int os_timer_one_shot(os_timer_t *timer);

/**
 * @brief Changes the interval that the timer will run at
 * @param os_timer_t *pointer to timer structure
 * @param uint32_t timer_period
 * @returns return status
*/
int os_timer_change_interval(os_timer_t *timer, uint32_t timer_periood);

/**
 * @brief Stops the timer from running 
*/
int os_timer_stop(os_timer_t *timer);
#endif