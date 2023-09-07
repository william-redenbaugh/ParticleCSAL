#include "global_includes.h"

#define SETBITS_QUEUE_SIZE 16

int os_setbits_init(os_setbits_t *mod)
{
    mod->bits = 0;
    os_queue_create(&mod->queue, sizeof(int), SETBITS_QUEUE_SIZE, NULL);
    return OS_RET_OK;
}

int os_setbits_signal(os_setbits_t *mod, int bit)
{
    if (mod == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    return OS_RET_OK;
}

int os_clearbits(os_setbits_t *mod, int bit)
{
    if (mod == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    return OS_RET_OK;
}

int os_waitbits(os_setbits_t *mod, uint8_t bit, uint32_t timeout_ms)
{
    if (mod == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    if (mod->counter == SETBITS_QUEUE_SIZE)
    {
    }

    os_mut_entry(&mod->counter_mut, 1000);
    mod->counter++;
    os_mut_exit(&mod->counter_mut);

    return OS_RET_OK;
}

int os_waitbits_indefinite(os_setbits_t *mod, int bit)
{
    if (mod == NULL)
    {
        return OS_RET_NULL_PTR;
    }
    return OS_RET_OK;
}