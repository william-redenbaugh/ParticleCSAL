#ifndef _PARTICLE_CSHAL_STRUCTS_H
#define _PARTICLE_CSHAL_STRUCTS_H

#include "stdint.h"
#include "stdbool.h"
#include "Particle.h"

typedef struct os_mut_t
{
    os_mutex_t lock;
    // Mutex lock;
} os_mut_t;

typedef struct os_sem_t
{
    os_semaphore_t lock;
} os_sem_t;

typedef struct os_thread_id_s
{
    Thread *handle;
} os_thread_id_s;

typedef struct os_setbits
{
    os_queue_t queue;
    int bits;
    int counter;
    os_mut_t counter_mut;
} os_setbits_t;

typedef struct os_udp_server
{
    UDP udp;
} os_udp_server_t;

typedef void *(os_timer_cb_t)(void);

#endif