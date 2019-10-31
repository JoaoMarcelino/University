//compile with: gcc -Wall stockmarket.c semlib.c -o stock
//using SysV semaphores
//Note: you can change all the operations of semaphores to make it work with POSIX semaphores

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h> 
#include <pthread.h>

#define NUM_WRITERS 5		// number of writers
#define NUM_READERS 5		// number of readers
#define STOCKLIST_SIZE 10  // stock list slots
#define MUTEX 0
#define STOP_WRITERS 1

typedef struct
{
	int readers;
	int slots[STOCKLIST_SIZE];
} mem_structure;

int semid, shmid;
pid_t childs[NUM_READERS + NUM_WRITERS];
mem_structure *stocklist;
sem_t stop_writers;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t writer_thread[NUM_WRITERS];
pthread_t reader_thread[NUM_READERS];
int idw[NUM_WRITERS];
int idr[NUM_READERS];

void cleanup(int signo) // clean up resources by pressing Ctrl-C
{
	int i = 0;
	while (i < (NUM_READERS + NUM_WRITERS))
		kill(childs[i++], SIGKILL);
	while (wait(NULL) != -1);

	if (semid >= 0){	// remove semaphores
		pthread_mutex_destroy(&mutex);
		sem_close(&stop_writers);
	}
	/*
	if (shmid >= 0) // remove shared memory
		shmctl(shmid, IPC_RMID, NULL);
	*/

	printf("Closing...\n");
	exit(0);
}


int get_stock_value()
{
	return 1 + (int) (100.0 * rand() / (RAND_MAX + 1.0));
}

int get_stock()
{
	return (int) (rand() % STOCKLIST_SIZE);
}

void write_stock(int n_writer, mem_structure *stocklist)
{
	int stock=get_stock();
	int stock_value=get_stock_value();
	stocklist->slots[stock] = stock_value;
	fprintf(stderr, "Stock %d updated by BROKER %d to %d\n", stock, n_writer, stock_value);
}

int writer_code(int n_writer)
{
	srand(getpid());

	while (1)
	{
		/*insert code here*/
		write_stock(n_writer,stocklist);
		sleep(1 + (int) (10.0 * rand() / (RAND_MAX + 1.0)));
	}

	exit(0);
}

void read_stock(int pos, int n_reader, mem_structure *stocklist)
{
		fprintf(stderr, "Stock %d read by client %d = %d\n", pos, n_reader, stocklist->slots[pos]);
}

int reader_code(int n_reader)
{
	srand(getpid());	// to obtain a different seed

	while (1)
	{
		/*insert code here*/
		read_stock(get_stock(),n_reader,stocklist);
		sleep(1 + (int) (3.0 * rand() / (RAND_MAX + 1.0)));
	}

	exit(0);
}

void monitor() // main process monitors the reception of Ctrl-C
	{
	struct sigaction act; 
	act.sa_handler = cleanup; 
	act.sa_flags = 0; 
	if ((sigemptyset(&act.sa_mask) == -1) || 
		(sigaction(SIGINT, &act, NULL) == -1)) 
		perror("Failed to set SIGINT to handle Ctrl-C");
	while(1){
		sleep(5);
		printf("Still working...\n");
		}
	exit(0);
	}


void *stock_writer(void *id_ptr){
	
	int i=0;
	while(1){
		sem_wait(&stop_writers);
		pthread_mutex_lock(&mutex);
		writer_code(idw[i++]);
		pthread_mutex_lock(&mutex);
		sem_post(&stop_writers);
		pthread_exit(NULL);
	}
}

void *stock_reader(void *id_ptr){
	int i=0;
	while(1){

		pthread_mutex_lock(&mutex);
		stocklist->readers++;
		if(stocklist->readers==1)
			sem_wait(&stop_writers);
		pthread_mutex_unlock(&mutex);


		reader_code(idr[i++]);

		pthread_mutex_lock(&mutex);
		stocklist->readers--;
		if(stocklist->readers==0)
		sem_post(&stop_writers);
		pthread_mutex_lock(&mutex);
	}
}

int main()
{
	int i = 0;
	//sem_init(&mutex,0,1);
	sem_init(&stop_writers,0,1);

	stocklist->readers = 0;

	for(i=0;i<NUM_WRITERS;i++){
		idw[i]=i;
  		pthread_create(&writer_thread[i],NULL,stock_writer,&idw[i]);
	}
	for (i++;i<NUM_READERS;i++){
		idr[i]=100+i;
		pthread_create(&reader_thread[i],NULL,stock_reader,&idr[i]);
	}


	monitor();
	exit(0);
}

