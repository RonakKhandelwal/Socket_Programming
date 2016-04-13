#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(){
	int sockfd;
	struct sockaddr_in address;
	int result;
	int input = open("hello.txt",O_RDONLY, 0777);
	char buff[512];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_port = 9734;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	int len = sizeof(address);

	result = connect(sockfd, (struct sockaddr*) &address, len);
	if(result == -1){
		perror("Cliet oops:");
		exit(1);
	}

	while(1){
		int l = read(input, buff, 512);
		printf("%s\n", buff);
		write(sockfd, buff, 512);
		if(l == 0){
			printf("File sent\n");
			break;
		}
	}
	
	

		
		/*printf("%s\n", buff);
		if(chars < 511){
			printf("File sent\n");*/
	

}