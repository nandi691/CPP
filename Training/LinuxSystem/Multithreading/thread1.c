/*
 * Compile Using
 * gcc -g -c hello_world.c -o hello_world.o
 * gcc -g hello_world.o -o hello_world.exe -lpthread
 * Run : ./hello_world.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>


static int thread_no = 0;

void Print(int thread_no, int count){
	printf("Printing %d %d",thread_no, count);
}
//Race condition
//Thread T1 or T2
//Depends on CPU scheduler
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
	pthread_t thread; //It is a data structure
	//Every thread is identified by DS called pthread_t
	//It is Opaque Data Structure and we need not know the internal DS
	static char * inp_str = "I am thread";
	//Input thread must be from heap or stack
	//Local members or stack members must not be used
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
	//static int thread_no = 0;
	//Any application will have atleast 1 thread and it is called main thread
	printf("Before thread create\n");
	thread_create();
	thread_create();
	thread_create();
	printf("Main function paused\n");
	//If Main thread dies, then all other thread dies
	//But vice versa is not true

	pause();
	return 0;
}

//Resources shared by thread
//Memory, CPU, access to hardware
//All thread are siblings, there is no parent child, no hierarchy
//Any thread can terminate any thread ,i.e thread cancellation
//Share same virtual address space of process
//Heap Memory, Sockets, FD, Global variables etc can be shared
//Stack memory cannot be shared.


//Kernel or OS schedule the Threads and not processes
//If thread gets seg-fault, entire process is terminated
//A signal is delivered per process and not per thread.
//Race condition is due to the fact that which thread the kernel allocates CPU
//Kernel schedules threads as per scheduling policy
