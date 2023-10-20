/*
 ============================================================================
 Name        : Client.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"client.h"
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	int valuesend =2;
	volatile int valuerec;
	Client_init();
	socket_send(valuesend);
	socket_recive(  valuerec);
	return EXIT_SUCCESS;
}
