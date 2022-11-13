
#ifndef TCP_H_
    #define TCP_H_

    #include "network.h"
    #include <sys/select.h>

    #define SELECT_TIMEOUT_SEC      1
    #define SELECT_TIMEOUT_USEC     1

    enum Select_Type {
        S_READ,
        S_WRITE,
        S_EXCEPT
    };

    struct select_data_s {
        struct timeval tv;
        fd_set read_fds;
        fd_set write_fds;
        fd_set ex_fds;
    };

    // Functions

    // Sockets:
        // tcp_socket_server_setup
        // this is necessary for a server to accept clients
        // it will bind the socket and make it listen
        uint8_t tcp_socket_server_setup(socket_t *socket);

    // Servers:
        // server_duties
        // this function handles all the server's duties, from sending to recieving information,
        // accepting new clients, disconnecting clients, it does everything, just make sure to call
        // it regularly
        void server_duties(socket_t *socket, connection_t **connections);

    // Select
    // you don't need to call these functions, they are called automatically
    // by your program at the right places
        void set_select_timeout(struct select_data_s *data);
        void setup_select_data(struct select_data_s *s_data);
        void add_fd_to_select_read(size_t fd, struct select_data_s *s_data);
        void add_fd_to_select_write(size_t fd, struct select_data_s *s_data);
        void add_fd_to_select_except(size_t fd, struct select_data_s *s_data);
        void fill_select_data_with_connections(connection_t *connections, struct select_data_s *s_data);
        int get_select_num(int server, connection_t *con);
        void tcp_accept_connection(socket_t *socket, connection_t **connections);

#endif
