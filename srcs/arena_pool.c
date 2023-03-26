#include "../includes/ft_ls.h"

void *malloc_pool(size_t size, t_pool *pool) {
    if (pool->max_size - (pool->cursor + 1) > size)
    {
        void *ret = pool->data + pool->cursor;
        pool->cursor += size;
        return (ret);
    }
    else
    {
        if (pool->next)
            return (malloc_pool(size, pool->next));
        else
        {
            pool->next = init_pool(pool, size);
            if (!pool->next)
                return 0;
            return malloc_pool(size, pool->next);
        }
    }
}

void *init_pool(t_pool *pool, size_t size) {
    t_pool *new_pool;

    new_pool = malloc(sizeof(t_pool));
    if (pool) {
        if (pool->max_size * 2 > size)
            new_pool->max_size = pool->max_size * 2;
        else
            new_pool->max_size = size;
    } else {
        if (!new_pool)
            return 0;
        new_pool->max_size = size;
    }
    if (pool)
        pool->next = new_pool;
    new_pool->cursor = 0;
    new_pool->data = malloc(new_pool->max_size);
    if (!new_pool->data)
        return 0;
    return new_pool;
}

void free_pool(t_pool *pool) {
    t_pool *buffer;

    if (pool) {
        while (pool->next) {
            free(pool->data);
            buffer = pool->next;
            free(pool);
            pool = buffer;
        }
    }
}

void panic(t_pool *pool, char *err_msg) {
    free_pool(pool);
    ft_printf("%s\n", err_msg);
}