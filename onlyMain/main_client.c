#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	WSADATA wsa;
	//SOCKET s;
	int sock =0, valread, client_fd;
	struct sockaddr_in server_addr;

	char* hello ;

	char buffer [1024]= {0};
//	char *message;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}

	printf("Initialised.\n");

	//Create a socket
	if((sock = socket(AF_INET , SOCK_STREAM , 0 )) <0)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
	}

	printf("Socket created.\n");


	//server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8080);
	// Convert IPv4 and IPv6 addresses from text to binary
	    // form
	    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr)  <= 0) {
	        printf(
	            "\nInvalid address/ Address not supported \n");
	        return -1;
	    }
	//Connect to remote server

	if ((client_fd= connect(sock , (struct sockaddr *)&server_addr , sizeof(server_addr))) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");

	printf("enter message:\n");
	scanf("%s",hello);

	send(sock, hello, strlen(hello), 0);
	//    printf("Hello message sent\n");
	  //  valread = read(sock, buffer, 1024);
	    recv(sock, buffer,1024,0);
	    printf("recieved msg from server %s\n", buffer);

	    // closing the connected socket
	    closesocket(client_fd);

	return 0;
}
