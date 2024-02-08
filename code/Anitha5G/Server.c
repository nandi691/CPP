#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include <errno.h>
#include "common.h"
#include <arpa/inet.h>


#define MAX_CLIENT_SUPPORTED    32
#define SERVER_PORT     2000

test_struct_t test_struct;
result_struct_t res_struct;
char data_buffer[1024];

int monitored_fd_set[32];

static void
intitiaze_monitor_fd_set(){

    int i = 0;
    for(; i < MAX_CLIENT_SUPPORTED; i++)
        monitored_fd_set[i] = -1;
}

static void
add_to_monitored_fd_set(int skt_fd){

    int i = 0;
    for(; i < MAX_CLIENT_SUPPORTED; i++){

        if(monitored_fd_set[i] != -1)
            continue;
        monitored_fd_set[i] = skt_fd;
        break;
    }
}

static void
remove_from_monitored_fd_set(int skt_fd){

    int i = 0;
    for(; i < MAX_CLIENT_SUPPORTED; i++){

        if(monitored_fd_set[i] != skt_fd)
            continue;

        monitored_fd_set[i] = -1;
        break;
    }
}

static void
re_init_readfds(fd_set *fd_set_ptr){

    FD_ZERO(fd_set_ptr);
    int i = 0;
    for(; i < MAX_CLIENT_SUPPORTED; i++){
        if(monitored_fd_set[i] != -1){
            FD_SET(monitored_fd_set[i], fd_set_ptr);
        }
    }
}

static int
get_max_fd(){

    int i = 0;
    int max = -1;

    for(; i < MAX_CLIENT_SUPPORTED; i++){
        if(monitored_fd_set[i] > max)
            max = monitored_fd_set[i];
    }

    return max;
}

void
setup_tcp_server_communication(){

    int master_sock_tcp_fd = 0,
        sent_recv_bytes = 0,
        addr_len = 0,
        opt = 1;

    int comm_socket_fd = 0;
    fd_set readfds;

    struct sockaddr_in server_addr,
                       client_addr;


    intitiaze_monitor_fd_set();

    if ((master_sock_tcp_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP )) == -1)
    {
        printf("socket creation failed\n");
        exit(1);
    }


    server_addr.sin_family = AF_INET;
    server_addr.sin_port = SERVER_PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    addr_len = sizeof(struct sockaddr);

    if (bind(master_sock_tcp_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        printf("socket bind failed\n");
        return;
    }

    if (listen(master_sock_tcp_fd, 5)<0)
    {
        printf("listen failed\n");
        return;
    }


    add_to_monitored_fd_set(master_sock_tcp_fd);


    while(1){
        re_init_readfds(&readfds);

        printf("blocked on select System call...\n");
        select(get_max_fd() + 1, &readfds, NULL, NULL, NULL);
        if (FD_ISSET(master_sock_tcp_fd, &readfds))
        {
            printf("New connection recieved recvd, accept the connection");
            comm_socket_fd = accept(master_sock_tcp_fd, (struct sockaddr *)&client_addr, &addr_len);
            if(comm_socket_fd < 0){
                printf("accept error : errno = %d\n", errno);
                exit(0);
            }

            add_to_monitored_fd_set(comm_socket_fd);
            printf("Connection accepted from client : %s:%u\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }
        else
        {

            int i = 0, comm_socket_fd = -1;
            for(; i < MAX_CLIENT_SUPPORTED; i++){


                if(FD_ISSET(monitored_fd_set[i], &readfds)){/*Find the clinet FD on which Data has arrived*/

                    comm_socket_fd = monitored_fd_set[i];

                    memset(data_buffer, 0, sizeof(data_buffer));
                    int dataSize = 0;
                    sent_recv_bytes = recvfrom(comm_socket_fd, (int *)&dataSize, 2, 0, (struct sockaddr *)&client_addr, &addr_len);
                    printf("Server recvd %d bytes from client %s:%u\n", sent_recv_bytes,
                            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    printf("char str length %d\n",dataSize);

                    if(sent_recv_bytes == 0){
                        close(comm_socket_fd);
                        remove_from_monitored_fd_set(comm_socket_fd);
                        break;

                    }

                    char * ptr = (char *)malloc(dataSize);
                    sent_recv_bytes = recvfrom(comm_socket_fd, (char *)ptr, dataSize, 0, (struct sockaddr *)&client_addr, &addr_len);
                                        printf("Server recvd %d bytes from client %s:%u\n", sent_recv_bytes,
                                                inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                                        printf("char str is %s\n",ptr);
                    free(ptr);
                    ptr = NULL;
                                        if(sent_recv_bytes == 0){
                                            close(comm_socket_fd);
                                            remove_from_monitored_fd_set(comm_socket_fd);
                                            break;

                                        }
                }
            }
        }

    }
}

int
main(int argc, char **argv){

    setup_tcp_server_communication();
    return 0;
}
