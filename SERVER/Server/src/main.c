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
#include "Server.h"
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	int valuesend=0;
	volatile int valuerec;
	 Socket_Init();
	 socket_recive(valuerec);
	 socket_send(valuesend);
	 return EXIT_SUCCESS;
}

