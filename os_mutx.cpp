#include "os_mutx.h"
#include "os_error.h"

int os_mut_init(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }

    mut->lock = Mutex();

    return OS_RET_OK;
}

int os_mut_entry(os_mut_t *mut, uint32_t timeout_ms){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }
    mut->lock.try_lock();

    return OS_RET_OK;
}

int os_mut_count(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }
    return OS_RET_OK;
}

int os_mut_entry_wait_indefinite(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }

    mut->lock.lock();
    return OS_RET_OK;
}

int os_mut_exit(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }
    mut->lock.unlock();

    return OS_RET_OK;
}
