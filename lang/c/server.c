/*
  File : Server.c 
  Author : Suresh Krishnan
  Server Socket Example
  Multithreaded Server Socket example
  - Create Server socket
  - for each client connection , spawn a new thread
  - in the thread 
  -   Receive data from client
  -   Sernd Data to the Clinet
  -   Close the socket and the thread is terminated
*/
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <pthread.h> 
#include <arpa/inet.h> 
#include <time.h>
#define PORT 8080 
typedef struct _thread_param
{
    pthread_t thread_id; /* ID returned by pthread_create() */
    int       client_socket;
} thread_param;

void*  processClientConnection(void *param);

/*
OpenServer 
    INPUT:
    char * ip   : IP Address
    int    port : port number
    RETURN:
    -1 : error
    socket
     
     
*/
int OpenServerSocket(char *ip, int port)
{
    int server_fd; 
	struct sockaddr_in address; 
	int opt = 1; 
	
	
	/* Creating socket file descriptor */
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		return -1; 
	} 
	
	// Forcefully attaching socket to the port 8080 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
												&opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		return -1; 
	} 
	address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY;
 	address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons( port ); 
    	
	// Forcefully attaching socket to the port 8080 
	if (bind(server_fd, (struct sockaddr *)&address, 
								sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		return -1; 
	} 
    return server_fd;
}
void*  processClientConnection(void *param)
{
        
    char buffer[64];       
    int rcvBytes;
    time_t rawtime;
    struct tm * timeinfo;
    thread_param * tp = (thread_param*) param;
    int client_socket = tp->client_socket;
    memset(buffer,0,64);;
    printf("\n->SRV:THREAD(%lu):%d:Start ...",tp->thread_id,client_socket);
    /* read from client */
    rcvBytes = read( client_socket , buffer, 64); 
	printf("\nSRV:THREAD(%lu):data from client %d bytes ",tp->thread_id,rcvBytes); 
    printf("\nData:[%s]",buffer);
    /* Send to clinet */
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );   
    sprintf(buffer, "Server time [%d %d %d %d:%d:%d]",
            timeinfo->tm_mday, timeinfo->tm_mon + 1, 
            timeinfo->tm_year + 1900, timeinfo->tm_hour, 
            timeinfo->tm_min, timeinfo->tm_sec);
    printf("\nSRV:THREAD(%lu): Send data to client ...",tp->thread_id);            
	send(client_socket , buffer , strlen(buffer) , 0 ); 
    
	 
    shutdown(client_socket,SHUT_RDWR);
    close(client_socket);
    printf("\n<-SRV:THREAD(%lu):%d:Exit\n",tp->thread_id,client_socket);
    free(param);
    return 0;
}

int main(int argc, char const *argv[]) 
{ 
    int srvsocket ,new_socket; 
    int iExit=0;   
    struct sockaddr_in client_address; 
    int addrlen = sizeof(client_address); 	
    int  max_connection=5;
    srvsocket = OpenServerSocket("127.0.0.1",PORT);
    if(srvsocket < 0){
        printf("\nApp:Error Opening server connection on port %d",PORT);
        exit(EXIT_FAILURE); 
    }  	
	if (listen(srvsocket, max_connection) < 0) 
	{ 
        printf("\nApp:Error Opening server connection on port %d",PORT);
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
    while(!iExit){
        printf("\nSRV:MAIN:Waiting for connection....\n");
        if ((new_socket = accept(srvsocket, (struct sockaddr *)&client_address, 
					(socklen_t*)&addrlen))<0) 
        { 
            perror("accept"); 
            iExit = 1;
		
        } 
        printf("\nSRV:MAIN:nNew connection %d : ", new_socket);  
        thread_param * tp = (thread_param*) malloc(sizeof(thread_param));       
        tp->client_socket = new_socket;
        if( pthread_create( &tp->thread_id , NULL ,  processClientConnection , (void*) tp) < 0)
        {
            perror("could not create thread");
            iExit =1;
        }
        /*sleep(1);*/
    }
    printf("\nAPP:Exit .....");
       
	
	return 0; 
} 
