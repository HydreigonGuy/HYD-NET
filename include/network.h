
#ifndef NETWORK_H_
    #define NETWORK_H_

    #include <netinet/in.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>

    #define MAX_BACKLOG     1000
    #define READ_SIZE       1024

    enum Status {
        READ,
        WRITE,
        EXCEPT,
        DISCONNECTED
    };

    typedef struct buffer_s {
        char *buff;
        struct buffer_s *next;
    } buffer_t;

    typedef struct connection_s {
        int fd;
        enum Status status;
        buffer_t *read_buff;
        buffer_t *write_buff;
        struct connection_s *next;
    } connection_t;

    typedef struct socket_s {
        int socket;
        struct sockaddr_in address;
    } socket_t;

    // Functions

    // Sockets:
        // create_socket
        // creates a socket with the given port
        socket_t *create_socket(size_t port);

        // create_connection_socket
        // creates a socket with the given IP and port
        // IP is given as a char * in the following format: "127.0.0.1\0"
        socket_t *create_connection_socket(size_t port, char *ip);

        // destroy_socket
        // destroys the given socket, closing the file descriptor and freeing memory
        void destroy_socket(socket_t *socket);

    // Connections:
        // create_connection
        // used to create a new connection
        // fd is the file descriptor of the new connection
        void create_connection(connection_t **connect, int fd);

        // change_status
        // this updates the status of your connection
        // you don't need to call this, it is already called at the apropriate times
        void change_status(connection_t *connect);

    // Buffers:
        // create_buffer
        // this function creates a buffer and ads it to the list of buffers
        // the new buffer will have the str string given as parameter as it's contents
        void create_buff(buffer_t **buff, char *str);

        // destroy_buffer
        // this destroys the buffer pointed to
        void destroy_buffer(buffer_t **buff);

    // Read:
        // read_socket
        // reads on the given fd and stores read data in the buffer list
        int read_socket(int fd, buffer_t **buff);

    // Write:
        // write_on_socket
        // this writes on the given fd from the given buffers and destroys what was written
        void write_on_socket(int fd, buffer_t **w_buff);

#endif
