#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(){

	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	char ch;
	printf("Enter the character\n");
	scanf("%c",&ch);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_port = 9734;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(address);

	result = connect(sockfd , (struct sockaddr*) &address, len);

	if(result == -1){
		perror("oops :: client");
		exit(1);
	}

	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	printf("%c\n", ch);
	close(sockfd);
	exit(0);

}