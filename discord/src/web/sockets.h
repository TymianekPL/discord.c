#ifndef SOCKETS_H
#define SOCKETS_H

#include <WinSock2.h>

typedef struct socketconnection
{
     SOCKET sock;
     SOCKADDR_IN addr;
     int addrlen;
} socketconnection_t;

socketconnection_t *socket_connect(char *host, int port);
int socket_send(socketconnection_t *conn, char *data, int len);
int socket_recv(socketconnection_t *conn, char *data, int len);
void socket_close(socketconnection_t *conn);

#endif