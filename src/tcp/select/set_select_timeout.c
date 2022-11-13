
#include "tcp.h"

void set_select_timeout(struct select_data_s *data)
{
    data->tv.tv_sec = SELECT_TIMEOUT_SEC;
    data->tv.tv_usec = SELECT_TIMEOUT_USEC;
}
