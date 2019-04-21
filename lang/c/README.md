# C Programs

## Threads 

*  thread.c
  [pthread_create](http://man7.org/linux/man-pages/man3/pthread_create.3.html)
  ```   
  gcc thread.c  
/tmp/cczaSilw.o: In function `SIMPLE':
thread.c:(.text+0x196): undefined reference to `pthread_create'
thread.c:(.text+0x1ea): undefined reference to `pthread_create'
thread.c:(.text+0x23f): undefined reference to `pthread_join'
thread.c:(.text+0x250): undefined reference to `pthread_join'
collect2: error: ld returned 1 exit status
  ```
```
gcc thread.c -lpthread -o thread
./thread
MAIN: Creating Threads ...... 

MAIN: Waiting for threads 
Thread 2 : [140662777034496]  START :  Thread2 ....:200  
Thread 1 : [140662785427200]  START :  Thread1 ....:100  
Thread 2 : [140662777034496]  STOP :  Thread2 ....:200 
Thread 1 : [140662785427200]  STOP :  Thread1 ....:100 

MAIN: Threads completed ... 

```

## Sockets 
* server.c
* client.c
```
gcc server.c -lpthread -o server
gcc client.c -o client

test.sh
#!/bin/bash

for i in {1..100}
do
   echo $i
   ./client
done

```
** Server Opens socket
** Server : Waits for client connection
** Server : Spawns thread for new client connection
** Server : Reads data from client and sends data to clinet and closes the socket
** Server Main process looks for client connection in a loop
** Client : Connects to Server
** Client :  Sends Data and receives data from server, closes the connection
```
./server 
SRV:MAIN:Waiting for connection....
SRV:MAIN:New connection 4 : 
SRV:MAIN:Waiting for connection....
SRV:THREAD(140525621880576):4:Start ...
SRV:THREAD(140525621880576):data from client 31 bytes 
Data:[Client time [21 4 2019 0:56:45]]
SRV:THREAD(140525621880576): Send data to client ...
SRV:THREAD(140525621880576):4:Exit

```
./client 
->Client:send data to server 
<-Client:rcv data from server 31 bytes 
Data[Server time [21 4 2019 0:56:45]]
```

```
