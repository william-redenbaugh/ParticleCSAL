#ifndef _PARTICLE_CSHAL_STRUCTS_H
#define _PARTICLE_CSHAL_STRUCTS_H

#include "stdint.h"
#include "stdbool.h"
#include "Particle.h"

typedef struct os_mut_t{
    os_mutex_t lock;
    //Mutex lock;
}os_mut_t;


typedef struct os_thread_id_s{
    Thread* handle;
}os_thread_id_s;

#endif