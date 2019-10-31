//compile with: gcc -Wall -pthread sharedvariable_posix.c -o svar
//using POSIX named semaphores

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h> // include POSIX semaphores
#include <sys/fcntl.h>

/*insert here the other libraries needed*/


int * shared_var;
int shmid;
sem_t mutex;  // sem_t *mutex;


void worker()
	{
	usleep(1000000 + rand()%11*100000); //uses microseconds sleep and waits 1 to 2 seconds in periods of 0.1 secs
	
	/*insert code here*/
	sem_wait(&mutex);
	printf("%d Working\n",getpid());
	(*shared_var)++;
	printf("Value Incremented to %d\n",*shared_var);
	printf("%d Leaving\n",getpid());
	sem_post(&mutex);
	
	}

int main(int argc, char *argv[])
	{
	int i, n_procs;
	if(argc!=2) {
		printf("Wrong number of parameters\n");
		exit(0);
		}


	n_procs=atoi(argv[1]);

	// Create shared memory
	if ((shmid= shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT| 0700))==-1){
		perror("Error in shamget with IPC_CREAT\n");
		exit(1);
	}
	
	// Attach shared memory
	if((shared_var=shmat(shmid,NULL,0))<=0){
		perror("Error in shmat\n");
		exit(1);
	}
	
	// Create semaphore
	sem_init(&mutex,0,1);
	// initialize variable in shared memory
	*shared_var=1000;
	
	
	// Create worker processes

	for(i=0;i<n_procs;i++){
		pid_t childpid=fork();
		if(childpid==0){
			worker();
			
			exit(0);
			
		}
	}
	
	
	// Wait for all worker processes
	for (i = 0; i < n_procs; i++) wait(NULL);

	// print final result
	printf("Valor Final %d",*shared_var);

	// remove resources (shared memory and semaphore)
	shmctl(shmid,IPC_RMID,NULL);
	sem_close(&mutex);

	exit(0);
}
