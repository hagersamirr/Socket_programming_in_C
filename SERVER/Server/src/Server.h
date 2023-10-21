/*
 * Server.h
 *
 *  Created on: Oct 19, 2023
 *      Author: Hager Samir
 */

#ifndef SERVER_H_
#define SERVER_H_


extern int new_sock;


void Socket_Init();
void socket_recive(char buffer[], int size);
void socket_send(char buffer[], int size);
//int socket_recive( int value);
//void socket_send( int value);




#endif /* SERVER_H_ */
