#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc , char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	int server_fd, new_sock, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024]={0};
	char* hello =" Hello from server";

	WSADATA wsa;
	
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
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
	if (listen(server_fd ,3)<0){
		puts ("listen error");
	}
	puts("listening...");


	//Accept and incoming connection
	//puts("Waiting for incoming connections...");

	//c = sizeof(struct sockaddr_in);
	//new_socket = accept(s , (struct sockaddr *)&client, &c);
	while(1){
	if ((new_sock =accept(server_fd , (struct sockaddr *)&address, &addrlen)) < 0)
	{
		printf("accept failed with error code : %d" , WSAGetLastError());
	}

	puts("Connection accepted");

   while(1){
	// valread = read(new_sock, buffer, 1024);
	 recv(new_sock, buffer,1024,0);
	  printf("buffer recieved from client %s\n", buffer);
	    send(new_sock, hello, strlen(hello), 0);
	//   printf("Hello message sent\n");
	    break;
        }
			    // closing the listening socket
   close(new_sock);
	}
	return 0;
}
