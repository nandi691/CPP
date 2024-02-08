#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <memory.h>
#include "common.h"

#define DEST_PORT            2000
#define SERVER_IP_ADDRESS   "127.0.0.1"

test_struct_t client_data;
result_struct_t result;

void
setup_tcp_communication(){

    int sockfd = 0,
        sent_recv_bytes = 0;

    int addr_len = 0;

    addr_len = sizeof(struct sockaddr);

    struct sockaddr_in dest;

    dest.sin_family = AF_INET;

    dest.sin_port = DEST_PORT;
    struct hostent *host = (struct hostent *)gethostbyname(SERVER_IP_ADDRESS);
    dest.sin_addr = *((struct in_addr *)host->h_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    connect(sockfd, (struct sockaddr *)&dest,sizeof(struct sockaddr));


PROMPT_USER:

	char str_[200];
	printf("Enter a string : ");
	fgets(str_,200,stdin);
	int dataLen = strlen((const char *)str_);
    sent_recv_bytes = sendto(sockfd,
    	   &dataLen,
           2,
           0,
           (struct sockaddr *)&dest,
           sizeof(struct sockaddr));

    printf("No of bytes to be sent = %d\n", sent_recv_bytes);

    sent_recv_bytes = sendto(sockfd,
    		   str_,
			   dataLen,
               0,
               (struct sockaddr *)&dest,
               sizeof(struct sockaddr));

     printf("char bytes sent = %d\n", sent_recv_bytes);
    goto PROMPT_USER;
}


int
main(int argc, char **argv){

    setup_tcp_communication();
    printf("application quits\n");
    return 0;
}
