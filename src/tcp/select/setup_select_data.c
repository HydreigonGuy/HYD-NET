
#include "tcp.h"

void setup_select_data(struct select_data_s *s_data)
{
    set_select_timeout(s_data);
    FD_ZERO(&s_data->read_fds);
    FD_ZERO(&s_data->write_fds);
    FD_ZERO(&s_data->ex_fds);
}
