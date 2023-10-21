
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>
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

char* socket_recive(char buffer[],int size)
{
//	int bytes;
   // printf("buffer in recv: %d",strlen(buffer));

	 recv(sock, buffer, size , 0);
	printf("Message recv: ");
	puts(buffer);
	 /*if(bytes < 0){
		printf("Error: send\n");
		exit(1);
	}*/
return buffer;
}

void socket_send(char buffer[],int size)
{
	//int bytes;

	 send(sock, buffer , size, 0);
	 printf("Message sent: %s \n", buffer);
	/*if(bytes < 0){
		printf("Error: send\n");
		exit(1);
	}*/
//	return bytes;
}
