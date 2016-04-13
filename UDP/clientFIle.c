#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>


int main(){
	int sockfd;
	struct sockaddr_in address;
	char buff[512];
	FILE* input = fopen("hello.txt", "r");
	int len;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	address.sin_family = AF_INET;
	address.sin_port = 9734;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(address);

	int reads = fread(buff, sizeof(char), 512, input);
	while(1){
		printf("%s\n", buff);
		sendto(sockfd, buff, 512, 0, (struct sockaddr*) &address, len);
		if(reads < 511){
			printf("File sent\n");
			break;
		}
		reads = fread(buff, sizeof(char), 512, input);

	}
	


}