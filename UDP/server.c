#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>


int main(){

	int client_sockfd, server_sockfd;
	struct sockaddr_in client_address, server_address;
	int client_len, server_len;

	char ch;
	server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_port = 9734;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_len = sizeof(server_address);

	bind(server_sockfd, (struct sockaddr*) &server_address, server_len);

	printf("Waitng for the data\n");
	while(1){

		int recv_length = recvfrom(server_sockfd, &ch, 1000, 0, (struct sockaddr*) &server_address, &server_len);
		printf("%c\n", ch);
	}

	


}