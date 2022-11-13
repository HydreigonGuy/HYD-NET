
#include "tcp.h"

void tcp_accept_connection(socket_t *socket, connection_t **connections)
{
    int addr_len = sizeof(socket->address);
    int client_socket = accept(socket->socket,
        (struct sockaddr *) &socket->address, (unsigned int *) &addr_len);

    if (client_socket == -1)
        return;
    create_connection(connections, client_socket);
}
