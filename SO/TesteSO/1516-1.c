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

#define TOTAL_MATRIZES 3

typedef struct mem_shared{
	int matrix[10][10];
	int n_processed;
	int matrix_number;
}mems;

int shmid;
mems *mems_ptr;

sem_t n_processed;
sem_t matrix_number;
sem_t matrix;

void counter(int id){
	int n=0; 
	int check=0;
	while(mems_ptr->matrix_number<3){
		if (check==0){
			for(int i=0;i<10;i++){
				for (int j=0;j<10;j++){
					sem_wait(&matrix);
					if (id == mems_ptr->matrix[i][j]){
						sem_wait(&n_processed);
						mems_ptr->n_processed++;
						n++;
						sem_post(&n_processed);
					}
					sem_post(&matrix);
				}
			}
			check=1;
		}
	printf("%dNumero de %d: %d\n",mems_ptr->matrix_number,id,n);
	n=0;
	sleep(3);
	check=0;
	}

}

void gerador(int aux){
	do{
		sem_wait(&n_processed);
		if (mems_ptr->n_processed>=100 || aux==0){
			mems_ptr->n_processed=0;
			sem_post(&n_processed);
			aux=1;
			sem_wait(&matrix);
			for(int i=0;i<10;i++){
				for (int j=0;j<10;j++){
					mems_ptr->matrix[i][j]=rand()%10;
				}
			}
			sem_post(&matrix);
			
			sem_wait(&matrix_number);
			mems_ptr->matrix_number++;
			sem_post(&matrix_number);
		}
		sem_post(&n_processed);
	}while(mems_ptr->matrix_number<3);
}



int main(void){

	pid_t id;

	if ((shmid=shmget(IPC_PRIVATE,sizeof(mems),IPC_CREAT|0700))<1){
		perror("Error creating shared mem");
		exit(1);
	}
	if ((mems_ptr=(mems *)shmat(shmid,NULL,0)) <(mems*)1){
		perror("Error in shmat");
		exit(1);
	}

	sem_init(&n_processed,0,1);
	sem_init(&matrix,0,1);
	sem_init(&matrix_number,0,1);
	mems_ptr->n_processed=0;
	mems_ptr->matrix_number=0;

	if ((id=fork())==0){
		gerador(0);
	}

	for(int i=0;i<10;i++){
		if ((id=fork())==0){
			counter(i);
		}
	}

	wait(NULL);
	shmdt(mems_ptr);
	shmctl(shmid,IPC_RMID,NULL);
}