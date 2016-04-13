#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


int main(){
	int sockfd;
	struct sockaddr_in address;
	int result, len;
	int ch;
	printf("Enter the character\n");
	scanf("%d",&ch);

	sockfd = socket(AF_INET,SOCK_DGRAM,0);

	address.sin_family = AF_INET;
	address.sin_port = 9734;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(address);
	sendto(sockfd, &ch, sizeof(ch), 0, (struct sockaddr*) &address, len);
	printf("Sent\n");
	recvfrom(sockfd, &ch, sizeof(ch), 0, (struct sockaddr*) &address, &len);
	printf("%d\n", ch);
	close(sockfd);
	return 0;
}	