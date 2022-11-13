
#include "network.h"
#include <unistd.h>

void destroy_socket(socket_t *socket)
{
    if (!socket)
        return;
    close(socket->socket);
    free(socket);
}
