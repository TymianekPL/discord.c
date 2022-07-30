#include "sockets.h"

socketconnection_t *socket_connect(char *host, int port)
{
     WSADATA wsaData;
     WSAStartup(MAKEWORD(2, 2), &wsaData);

     socketconnection_t *connection = malloc(sizeof(socketconnection_t));
     printf("Opening connection to %s\n", host);
     SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0)
     {
          printf("Discord: Error creating socket: %d\n", WSAGetLastError());
          return NULL;
     }
     printf("Connecting to %s\n", host);

     struct sockaddr_in server_addr;
     server_addr.sin_family = AF_INET;
     server_addr.sin_port = htons(port);
     server_addr.sin_addr.s_addr = inet_addr(host);

     printf("Connecting to %s:%d\n", host, port);

     if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
     {
          printf("Discord: Error connecting to server: %d\n", WSAGetLastError());
          return NULL;
     }

     connection->sock = sockfd;

     return connection;
}

int socket_send(socketconnection_t *conn, char *data, int len)
{
     int sent = send(conn->sock, data, len, 0);
     if (sent < 0)
     {
          return -1;
     }

     return sent;
}

int socket_recv(socketconnection_t *conn, char *data, int len)
{
     int received = recv(conn->sock, data, len, 0);
     if (received < 0)
     {
          return -1;
     }

     return received;
}

void socket_close(socketconnection_t *conn)
{
     closesocket(conn->sock);
     free(conn);

     WSACleanup();
}