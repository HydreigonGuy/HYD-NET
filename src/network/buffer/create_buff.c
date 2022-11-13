
#include "network.h"
#include <string.h>
#include <stdlib.h>

buffer_t *new_buffer(void)
{
    buffer_t *buff = malloc(sizeof(buffer_t));

    if (!buff)
        return (NULL);
    buff->buff = NULL;
    buff->next = NULL;
    return (buff);
}

void create_buff(buffer_t **buff, char *str)
{
    buffer_t *tmp = *buff;

    if (!tmp) {
        *buff = new_buffer();
        tmp = *buff;
        if (!tmp)
            return;
        tmp->buff = strdup(str);
    } else {
        for (; tmp && tmp->next; tmp = tmp->next);
        tmp->next = new_buffer();
        if (!tmp->next)
            return;
        tmp->next->buff = strdup(str);
    }
}

