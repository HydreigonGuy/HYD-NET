
#include "network.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stddef.h>

socket_t *create_socket(size_t port)
{
    socket_t *new_socket = malloc(sizeof(socket_t));

    if (!new_socket)
        return (NULL);
    new_socket->socket = socket(AF_INET, SOCK_STREAM, 0);
    new_socket->address.sin_family = AF_INET;
    new_socket->address.sin_port = htons(port);
    inet_aton("127.0.0.1", (struct in_addr *) &new_socket->address.sin_addr.s_addr);
    return (new_socket);
}
