/*
 * Server.c
 *
 *  Created on: Oct 19, 2023
 *      Author:
 */



#include<stdio.h>
#include<winsock2.h>
//#include "iso2EXIDatatypes.h"
#include"Server.h"
	int new_sock;


void Socket_Init()
{
	int server_fd;
	int valread;

	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024]={0};
		char* hello =" Hello from server";
	WSADATA wsa;

	printf("\nInitialising Winsock...");

	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		exit(1);
	}

	printf("Initialised.\n");

	//Create a socket
	if((server_fd = socket(AF_INET , SOCK_STREAM , 0 )) < 0)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
	}

	printf("Socket created.\n");

	//Prepare the sockaddr_in structure
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;

	//address.sin_addr.s_addr = inet_addr("192.168.1.12");
	address.sin_port = htons( 8080 );

	//Bind
	if( bind(server_fd ,(struct sockaddr *)&address , sizeof(address)) <0)
	{
		printf("Bind failed with error code : %d" , WSAGetLastError());
	}

	puts("Bind done");


	//Listen to incoming connections
	if (listen(server_fd ,3)<0)
	{
		puts ("listen error");
	}
	puts("listening...");

			if ((new_sock = accept(server_fd , (struct sockaddr *)&address, &addrlen)) < 0)
			{
				printf("accept failed with error code : %d" , WSAGetLastError());
			}

			puts("Connection accepted");

}

int socket_recive(int value)
{
	//int bytes;
	//int val;

     recv(new_sock, (char*)&value, sizeof(int), 0);

	printf("Message recv: %d \n", value);

	//val = value;

	/*if(bytes < 0)
	{
		printf("Error: send\n");
		exit(1);
	}*/
	return value;
}

void socket_send(int value)
{
	//int bytes;
//	printf("Message sent: %d \n", value);
	 send(new_sock, (char*) &value, sizeof(int), 0);
	 printf("Message sent: %d \n", value);
	 /*if(bytes < 0)
	{
		printf("Error: send\n");
		exit(1);
	}*/
	//return bytes;
}
