/* 
file : thread.c
gcc thread.c -lpthread -o thread
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

typedef struct _thread_param 
{ 
   pthread_t thread_id;        /* ID returned by pthread_create() */
   char         param1[50]; 
   int            param2;
}thread_param;


void*  tfn1( void *ptr );
void*  tfn2( void *ptr );

#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

/* Thread functions */
/* tf1 and tfn2 thread does not return any values */
void* tfn1( void *ptr )
{
	thread_param *tp = (thread_param *) ptr;   
    printf("Thread 1 : [%lu]  START :  %s:%d  \n", tp->thread_id,
	                                                                    tp->param1,
																		tp->param2);    
    sleep(6);
    printf("Thread 1 : [%lu]  STOP :  %s:%d \n", tp->thread_id
	                                                                 ,tp->param1,
																	 tp->param2);   
}
void* tfn2( void *ptr )
{
	thread_param *tp = (thread_param *) ptr;   
    printf("Thread 2 : [%lu]  START :  %s:%d  \n", tp->thread_id, 
                                                                         tp->param1,
																		 tp->param2);    
    sleep(3);
    printf("Thread 2 : [%lu]  STOP :  %s:%d \n", tp->thread_id,  
	                                                                  tp->param1, 
																	  tp->param2);   
}

void SIMPLE()
{
	
	thread_param   tp1,tp2;
	int ret;
	/* Initialize Parametrs to be passed to the threads */
	strcpy(tp1.param1, "Thread1 ....");
	tp1.param2 = 100;
	strcpy(tp2.param1, "Thread2 ....");
	tp2.param2 = 200;
	/* Spawn the threads */
	printf("\nMAIN: Creating Threads ...... \n");
    ret = pthread_create( &tp1.thread_id, NULL, tfn1, (void*) &tp1);
	/* exit if error in thread creation */
	if(ret !=0)
		handle_error_en(ret, "pthread_create");
	/* exit if error in thread creation */
    ret= pthread_create( &tp2.thread_id, NULL, tfn2, (void*) &tp2);
	if(ret !=0)
		handle_error_en(ret, "pthread_create");
	 /* Wait for Thread completion 
	    Not expecting thread to return value
	 */
	 printf("\nMAIN: Waiting for threads \n");
	 pthread_join( tp1.thread_id, NULL);
     pthread_join( tp2.thread_id, NULL); 
	 
	 printf("\nMAIN: Threads completed ... \n");
}

int main(int argc, char ** argv)
{
	int  nothreads=1;
	if(argc ==2){
		nothreads = atoi(argv[1]);
	}
	SIMPLE();
	
}
    

