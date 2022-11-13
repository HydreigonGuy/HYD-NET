
#include "tcp.h"

void add_fd_to_select_read(size_t fd, struct select_data_s *s_data)
{
    FD_SET(fd, &s_data->read_fds);
}

void add_fd_to_select_write(size_t fd, struct select_data_s *s_data)
{
    FD_SET(fd, &s_data->write_fds);
}

void add_fd_to_select_except(size_t fd, struct select_data_s *s_data)
{
    FD_SET(fd, &s_data->ex_fds);
}
