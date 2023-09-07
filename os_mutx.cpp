#include "global_includes.h"

int os_mut_init(os_mut_t *mut)
{
    if (mut == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    if (os_mutex_create(&mut->lock) < 0)
    {
        return OS_RET_INT_ERR;
    }

    return OS_RET_OK;
}

int os_mut_deinit(os_mut_t *mut)
{
    if (mut == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    if (os_mut_count(mut) > 0)
    {
        return OS_RET_DEADLOCK;
    }
    os_mutex_destroy(mut->lock);

    return OS_RET_OK;
}

int os_mut_entry(os_mut_t *mut, uint32_t timeout_ms)
{
    if (mut == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    os_mutex_lock(mut->lock);

    return OS_RET_OK;
}

int os_mut_try_entry(os_mut_t *mut)
{
    if (mut == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    bool locked = os_mutex_trylock(mut->lock);

    if (locked < 0)
    {
        return OS_RET_OK;
    }
    else
    {
        return OS_RET_MAX_RENTRANT;
    }
}

int os_mut_entry_wait_indefinite(os_mut_t *mut)
{
    if (mut == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    os_mutex_lock(mut->lock);
    return OS_RET_OK;
}

int os_mut_count(os_mut_t *mut)
{
    bool if_locked = (os_mutex_trylock(mut->lock) < 0);
    if (if_locked == true)
    {
        os_mutex_unlock(mut->lock);
        return 0;
    }

    return 1;
}

int os_mut_exit(os_mut_t *mut)
{
    if (mut == NULL)
    {
        return OS_RET_NULL_PTR;
    }

    os_mutex_unlock(mut->lock);
    return OS_RET_OK;
}
