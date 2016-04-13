#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int server_sockfd, client_sockfd;
	struct sockaddr_in server_addr, client_addr;
	int server_len, client_len;
	char buff[512];

	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = 9734;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_len = sizeof(server_addr);

	bind(server_sockfd, (struct sockaddr *)&server_addr, server_len);

	listen(server_sockfd, 5);
	while(1){
		printf("Server Waiting\n");
		client_len = sizeof(client_addr);
		client_sockfd = accept(server_sockfd, (struct sockaddr*) &client_addr, &client_len);
		if(client_sockfd == -1){
			perror("Error\n");
			exit(1);
		}
		printf("Connected\n");
		
		while(1){
			int l = read(client_sockfd, buff, 512);
			printf("%s\n", buff);
			if(l == 0){
				printf("File Receved \n");
				break;
			}
		}

    }


}