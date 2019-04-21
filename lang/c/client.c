/*
File: Client.c
Author : Suresh Krishnan
Client Socket Application :
- Connect to server socket 
- Send Data to Server
- Receive Data from Server
- Close socket

*/ 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <time.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080 

/*
 * OpenClientSocket
 * IN:
 * char* ipaddress : Server IP address
 * int port        : Server port number 
 * RETURN:
 * -1              : if error
 * int             : socket number
*/
int OpenClientSocket(char *ipaddress, int port)
{
    
    struct sockaddr_in serv_addr; 
    int sock = 0;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	memset(&serv_addr, '0', sizeof(serv_addr)); 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(port); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, ipaddress, &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
    return sock;
}

void serverhandshake(int sock)
{
    char buffer[64];
    int rcvBytes;   
    time_t rawtime;
    struct tm * timeinfo;
    /* Send to clinet */
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    sprintf(buffer, "Client time [%d %d %d %d:%d:%d]",
            timeinfo->tm_mday, timeinfo->tm_mon + 1, 
            timeinfo->tm_year + 1900, timeinfo->tm_hour, 
            timeinfo->tm_min, timeinfo->tm_sec);
    printf("\n->Client:send data to server ");             
	send(sock , buffer , strlen(buffer) , 0 );    
    /* read from Server */
    rcvBytes = read( sock , buffer, 64); 
	printf("\n<-Client:rcv data from server %d bytes ",rcvBytes); 
    printf("\nData[%s]\n",buffer); 
    shutdown(sock,SHUT_RDWR);
    close(sock);   
}

int main(int argc, char const *argv[]) 
{ 
	int sock;
    char czServer[]="127.0.0.1";
    int  port = PORT;
    sock = OpenClientSocket(czServer,port);
    if( sock < 0) {
        printf("\nClient: error establishing connection %s:%d ",czServer,port);
    }else{
        serverhandshake(sock);
    }    
} 
