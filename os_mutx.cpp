#include "os_mutx.h"
#include "CSAL_SHARED/os_error.h"

int os_mut_init(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }

    mut->lock.~Mutex();
    mut->lock.unlock();

    return OS_RET_OK;
}

int os_mut_deinit(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }

    if(os_mut_count(mut) > 0){
        return OS_RET_DEADLOCK;
    }

    // Remove Mutex
    mut->lock.dispose();
}

int os_mut_entry(os_mut_t *mut, uint32_t timeout_ms){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }
    mut->lock.lock();
    
    return OS_RET_OK;
}

int os_mut_try_entry(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }

    bool locked = mut->lock.try_lock();

    if(locked){
        return OS_RET_OK;
    }
    else{
        return OS_RET_MAX_RENTRANT;
    }
}

int os_mut_entry_wait_indefinite(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }

    mut->lock.lock();
    return OS_RET_OK;
}

int os_mut_count(os_mut_t *mut){
    bool if_locked = mut->lock.try_lock();
    if(if_locked == true){
        mut->lock.unlock();
        return 0;
    }

    return 1;
}

int os_mut_exit(os_mut_t *mut){
    if(mut == NULL){
        return OS_RET_NULL_PTR;
    }
    mut->lock.unlock();

    return OS_RET_OK;
}
