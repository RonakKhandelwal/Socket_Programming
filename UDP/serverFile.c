#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int sockfd, client_sockfd;
	struct sockaddr_in address, client_address;
	int num, server_len, recv_len, client_len = sizeof(client_address);
	char buff[512];

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = 9734;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_len = sizeof(address);
	bind(sockfd, (struct sockaddr*) &address, server_len);

	printf("Waiting for data\n");
	FILE* output = fopen("Recvd.txt", "w");
	while(1){
		client_len = sizeof(client_address);
		recv_len = recvfrom(sockfd, &buff, 512, 0, (struct sockaddr*) &client_address, &client_len);
		printf("Got a client\n");
		printf("%s\n", buff);
		int written = fprintf(output, "%s\n", buff);
		printf("%d\n", written);
		if(recv_len < 511){
			printf("File Recvd\n");
		}
	}
}