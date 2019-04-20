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