/*
 ============================================================================
 Name        : Server.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Server.h"
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	char buffer [1024] ={0};
	char hello [1024] =" Hello from server";
	 Socket_Init();
	 socket_recive(buffer,1024);
	 socket_send(hello,1024);
	 return EXIT_SUCCESS;
}

