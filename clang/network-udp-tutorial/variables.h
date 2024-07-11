#ifndef VARIABLES_H
#define VARIABLES_H

#include <winsock.h>
#include <time.h>

#define WINSOCK_VERSION 0x0101
WSADATA w;                  /* Used to open windows connection */
unsigned short port_number; /* Port number to use */
int a1, a2, a3, a4;         /* Components of address in xxx.xxx.xxx.xxx form */
SOCKET sd;                  /* Socket descriptor of server */
struct sockaddr_in server;  /* Information about the server */
struct sockaddr_in client;  /* Information about the client */
struct hostent *hp;         /* Information about this computer */
char host_name[256];        /* Name of the server */
time_t current_time;        /* Current time */

// server only
#define BUFFER_SIZE 4096
int client_length;        /* Length of client struct */
int bytes_received;       /* Bytes received from client */
char buffer[BUFFER_SIZE]; /* Where to store received data */

// client only
#define SIZE 500
int b1, b2, b3, b4;                      /* Client address components in xxx.xxx.xxx.xxx form */
char send_buffer[SIZE] = "GET TIME\r\n"; /* Data to send */
int server_length;                       /* Length of server struct */

#endif // VARIABLES_H
