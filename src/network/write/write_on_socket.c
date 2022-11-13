
#include "network.h"
#include <unistd.h>
#include <string.h>

void write_on_socket(int fd, buffer_t **w_buff)
{
    int len = 0;
    int written = 0;
    int i = 0;
    buffer_t *buff = *w_buff;

    if (!buff)
        return;
    len = strlen(buff->buff);
    written = write(fd, buff->buff, len);
    if (written == len) {
        destroy_buffer(w_buff);
    } else {
        for (; written < len; i++, written++)
            buff->buff[i] = buff->buff[written];
        buff->buff[i] = '\0';
    }
}

