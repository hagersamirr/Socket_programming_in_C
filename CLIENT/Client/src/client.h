/*
 * client.h
 *
 *  Created on: Oct 19, 2023
 *      Author: BEBAWY
 */

#ifndef CLIENT_H_
#define CLIENT_H_


extern int new_sock;
extern int sock;


void Client_init();
int socket_recive( int value);
void socket_send( int value);



#endif /* CLIENT_H_ */
