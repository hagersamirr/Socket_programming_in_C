
#include <stdio.h>
#include <winsock2.h>
#include "client.h"


int new_sock;
int client_fd;
int sock;


void Client_init()
{

	WSADATA wsa;

	struct sockaddr_in server_addr;


	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());

	}

	printf("Initialised.\n");

	//Create a socket
	if((sock = socket(AF_INET , SOCK_STREAM , 0 )) <0)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
	}

	printf("Socket created.\n");


	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080);
	// form
	if (inet_pton(AF_INET, "192.168.56.1", &server_addr.sin_addr)  <= 0) {
		printf(
				"\nInvalid address/ Address not supported \n");

	}
	//Connect to remote server

	if ((client_fd= connect(sock , (struct sockaddr *)&server_addr , sizeof(server_addr))) < 0)
	{
		puts("connect error");
	}

	puts("Connected");


	// closing the connected socket
	closesocket(client_fd);

}

int socket_recive(int value)
{
//	int bytes;
	 recv(sock, (char*)&value, sizeof(value), 0);
	printf("Message recv: %d \n", value);
	/*if(bytes < 0){
		printf("Error: send\n");
		exit(1);
	}*/
	return value;
}

void socket_send(int value)
{
	//int bytes;

	 send(sock, (char*)&value, sizeof(value), 0);
	 printf("Message sent: %d \n", value);
	/*if(bytes < 0){
		printf("Error: send\n");
		exit(1);
	}*/
//	return bytes;
}
