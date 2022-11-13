
#include "network.h"

uint8_t tcp_socket_server_setup(socket_t *socket)
{
    if (bind(socket->socket, (struct sockaddr *) &socket->address,
    sizeof(socket->address)) == -1) {
        destroy_socket(socket);
        return (0);
    }
    if (listen(socket->socket, MAX_BACKLOG) == -1) {
        destroy_socket(socket);
        return (0);
    }
    return (1);
}
