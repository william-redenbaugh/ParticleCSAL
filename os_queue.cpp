#include "os_queue.h"
#include "CSAL_SHARED/os_error.h"

int os_queue_init(os_queue_t *queue, int max_elements){
    if(os_queue_create(queue, sizeof(void*), max_elements, 0) < 0)
        return OS_RET_INT_ERR;

    return OS_RET_OK;
}

int os_queue_push_timeout(os_queue_t *queue, void *data, int timeout_ms){
    if(queue == NULL){
        return OS_RET_NULL_PTR;
    }

    if(os_queue_put(*queue, data, timeout_ms, 0) < 0){
        return OS_RET_INT_ERR;
    }

    return OS_RET_OK;
}

int os_queue_push_indefinite(os_queue_t *queue, void *data){
    if(queue == NULL){
        return OS_RET_NULL_PTR;
    }

    if(os_queue_put(*queue, data, UINT32_MAX, 0) < 0){
        return OS_RET_INT_ERR;
    }

    return OS_RET_OK;
}

void* os_queue_pop_timeout(os_queue_t *queue, int timeout_ms){
    if(queue == NULL){
        return NULL;
    }

    void *item;
    if(os_queue_take(*queue, (void*)&item, timeout_ms, 0) < 0){
        return NULL;
    }    

    return item;
}

void *os_queue_pop_indefinite(os_queue_t *queue){
    if(queue == NULL){
        return NULL;
    }

    void *item;
    if(os_queue_take(*queue, (void*)&item, UINT32_MAX, 0) < 0){
        return NULL;
    }    

    return item;
}