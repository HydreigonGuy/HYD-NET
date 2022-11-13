
#include "tcp.h"

// ADD:     add_fd_to_select_read(0, &s_data);
// after    setup_select_data(&s_data);
// in order to handle standard input

void server_duties(socket_t *socket, connection_t **connections)
{
    struct select_data_s s_data;

    setup_select_data(&s_data);
    add_fd_to_select_read(socket->socket, &s_data);
    fill_select_data_with_connections(*connections, &s_data);
    if (select(get_select_num(socket->socket, *connections),
        &s_data.read_fds, &s_data.write_fds, &s_data.ex_fds, &s_data.tv) == -1)
        return;
    if (FD_ISSET(socket->socket, &s_data.read_fds))
        tcp_accept_connection(socket, connections);
    for (connection_t *iterator = *connections; iterator; iterator = iterator->next) {
        if (iterator->status == READ && FD_ISSET(iterator->fd, &s_data.read_fds))
            if (!read_socket(iterator->fd, &iterator->read_buff))
                iterator->status = DISCONNECTED;
        if (iterator->status == WRITE && FD_ISSET(iterator->fd, &s_data.write_fds))
            write_on_socket(iterator->fd, &iterator->write_buff);
        if (FD_ISSET(iterator->fd, &s_data.ex_fds))
            iterator->status = DISCONNECTED;
        change_status(iterator);
    }
}
