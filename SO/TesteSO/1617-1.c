#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/fcntl.h>
#include <semaphore.h> 
#include <pthread.h>
#include <regex.h>
#include <stdbool.h>
#include <sys/timeb.h>
#include <sys/msg.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define PIPE_NAME1 "PIPE1"
#define PIPE_NAME2 "PIPE2"

int fd_named_pipe[2];
int soma_total = 0;
int total=0;
int final = 0;
pthread_t threadPipe1, threadPipe2;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *lerPipe1(){
	int number;
	read(fd_named_pipe[0],&number,sizeof(number));
	while(number==-1){
		pthread_mutex_lock(&mutex);
		soma_total+=number;
		total++;
		printf("Nº%d:	soma:%d",total,soma_total);
		pthread_mutex_unlock(&mutex);
		read(fd_named_pipe[0],&number,sizeof(number));
	}
	//pthread_mutex_lock(&mutex);
	final=1;
	//pthread_mutex_unlock(&mutex);
}

void *lerPipe2(){
	int number;
	read(fd_named_pipe[1],&number,sizeof(number));
	while(number==-1){
		pthread_mutex_lock(&mutex);
		soma_total+=number;
		total++;
		printf("Nº%d:	soma:%d",total,soma_total);
		pthread_mutex_unlock(&mutex);
		read(fd_named_pipe[1],&number,sizeof(number));
	}
	//pthread_mutex_lock(&mutex);
	final=1;
	//pthread_mutex_unlock(&mutex);
}

int main(){

	unlink(PIPE_NAME1);

	if((mkfifo(PIPE_NAME1, O_CREAT | O_EXCL | 0600) < 0) && (errno != EEXIST)){
		perror("Cannot open named pipe");
		exit(0);
	}

	if ((fd_named_pipe[0] = open(PIPE_NAME1, O_RDWR)) < 0) {
		perror("Cannot open pipe for read/write: ");
		exit(0);
	}

	unlink(PIPE_NAME2);

	if((mkfifo(PIPE_NAME2, O_CREAT | O_EXCL | 0600) < 0) && (errno != EEXIST)){
		perror("Cannot open named pipe");
		exit(0);
	}

	if ((fd_named_pipe[1] = open(PIPE_NAME2, O_RDWR)) < 0) {
		perror("Cannot open pipe for read/write: ");
		exit(0);
	}

	pthread_create(&threadPipe1,NULL,&lerPipe1,NULL);
	pthread_create(&threadPipe2,NULL,&lerPipe2,NULL);
	do{
		if(final==1)
			printf("Nº%d:	soma:%d",total,soma_total);
	}while(final!=1);

	pthread_join(threadPipe1,NULL);
	pthread_join(threadPipe2,NULL);

	unlink(PIPE_NAME1);
	remove(PIPE_NAME1);
	unlink(PIPE_NAME2);
	remove(PIPE_NAME2);
}