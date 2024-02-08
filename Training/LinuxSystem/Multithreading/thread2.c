#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>


static int thread_no = 0;

void Print(int thread_no, int count){
	printf("Printing %d %d",thread_no, count);
}
static void * thread_fn_callback(void * args){
	int count = 0;
	char * str = (char *)args;
	thread_no++;
	printf("Before start of while for thread %d\n",thread_no);
	int thread__no = thread_no;
	while(count<5){
		++count;
		printf("%s%d %d\n",str,thread__no,count);
		printf("");
		sleep(1);
	}

	return NULL;
}

void thread_create(){
	printf("start of thread_create()");
	pthread_t thread;
	static char * inp_str = "I am thread";
	int rc = pthread_create(&thread,
							NULL,
							thread_fn_callback,
							(void *)inp_str);
	if(rc != 0){
		printf("Error in pthread_create, errno = %d\n", rc);
		exit(0);
	}
}

int main (int argc, char ** argv){
	printf("Before thread create\n");
	thread_create();
	thread_create();
	thread_create();
	pause();
	return 0;
}

/*
 * 2 Modes - Joinable , Detached
 */


