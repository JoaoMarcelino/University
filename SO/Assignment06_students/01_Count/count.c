/************************************************************************************
* FILE: count.c
* Compile as : gcc count_solution.c -lpthread -D_REENTRANT -Wall -o count
* DESCRIPTION:
*   NUM_WORKER_THREADS threads increase a counter a random number of times between 2 and 5
*   1 monitor thread watches the end of each worker thread
*   When all threads finish, the monitor thread prints the counter and leaves
*************************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_WORKER_THREADS  5

int count = 0;
int exited_threads=0;

/* initialize count_mutex and count_threshold_cv condition variable */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t count_threshold_cv = PTHREAD_COND_INITIALIZER;
/*insert code here - mutex and condition variable*/


void *increment_count(void *t) 
{
  long my_id = (long)t;
  int loops,i;

  loops=rand()%4+2; // increments a number between 2 and 5 times
  printf("Thread %ld started incrementing counter - will do it %d times\n", my_id,loops);

  /*insert code here - increment counter and wait 1 sec between each change*/
  for(i=0;i<loops;i++){
    pthread_mutex_lock(&mutex);
    count++;
    printf("Thread %ld just incremented count to %d\n",my_id,count);
    pthread_mutex_unlock(&mutex);
    sleep(1);

  }
  /*insert code here - notify monitor thread before leaving*/
  pthread_mutex_lock(&mutex);
  exited_threads++;
  printf("Thread %ld leaving!\n", my_id);
  pthread_cond_signal(&count_threshold_cv);
  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}


void *watch_threads(void *t) 
{
  long my_id = (long)t;

  printf("Thread %ld started watching threads\n", my_id);


  /*insert code here - when all threads leave print the counter*/
  pthread_mutex_lock(&mutex);
  while(exited_threads<NUM_WORKER_THREADS){
    pthread_cond_wait(&count_threshold_cv,&mutex);
  }
  printf("watch_threads: all threads are gone and the counter reached %d!",count);
  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}


int main (int argc, char *argv[])
{
  int i=0;
  long id[NUM_WORKER_THREADS+1];
  pthread_t threads[NUM_WORKER_THREADS+1];

  srand(time(NULL));

  /*insert code here - create threads*/
  id[i]=i;
  pthread_create(&threads[i],NULL,watch_threads,(void *)&id[i]);
  sleep(1);
  for(i=1;i<NUM_WORKER_THREADS+1;i++){
    id[i]=i;
    pthread_create(&threads[i],NULL,increment_count,(void *)&id[i]);
  }

  /*insert code here - wait for all threads to complete*/
  for (i = 0; i < NUM_WORKER_THREADS+ 1; i++) {
    pthread_join(threads[i], NULL);
  }

  /*insert code here - clean up and exit*/
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&count_threshold_cv);
  exit(0);
}

