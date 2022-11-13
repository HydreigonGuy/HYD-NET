
#include "tcp.h"

void fill_select_data_with_connections(connection_t *connections, struct select_data_s *s_data)
{
    for (connection_t *iterator = connections; iterator; iterator = iterator->next) {
        if (iterator->status == READ)
            add_fd_to_select_read(iterator->fd, s_data);
        if (iterator->status == WRITE)
            add_fd_to_select_write(iterator->fd, s_data);
        add_fd_to_select_except(iterator->fd, s_data);
    }
}
