#include "global_includes.h"

int os_setbits_init(os_setbits_t *mod)
{

    return OS_RET_OK;
}

int os_setbits_signal(os_setbits_t *mod, int bit)
{
    return OS_RET_OK;
}

int os_clearbits(os_setbits_t *mod, int bit)
{
    return OS_RET_OK;
}

int os_waitbits(os_setbits_t *mod, uint8_t bit, uint32_t timeout_ms)
{
    return OS_RET_OK;
}

int os_waitbits_indefinite(os_setbits_t *mod, int bit)
{
    return OS_RET_OK;
}