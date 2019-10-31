//compile with: gcc -Wall sharedvariable_sysv.c semlib.c -o svar
//using SysV semaphores
 
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
 
/*insert here the other libraries needed*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
 
int * shared_var;
int shmid, semid;
 
void worker()
    {
    usleep(1000000 + rand()%11*100000); //uses microseconds sleep and waits 1 to 2 seconds in periods of 0.1 secs
    /*insert code here*/
    sem_wait(semid, 0);
    (*shared_var)++;
    sem_post(semid,0);
 
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
    /*insert code here*/
    if((shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0766)) < 0){
        perror("error in shmget");
        exit(1);
    }
 
    // Attach shared memory
    /*insert code here*/
    if((shared_var = (int *) shmat(shmid, NULL, 0)) == (int *)-1){
        perror("error in shmat");
        exit(1);
    }
 
    // Create semaphores
    /*insert code here*/
    semid = sem_get(1,1);
 
    // initialize variable in shared memory
    /*insert code here*/
    *shared_var = 1000;
 
    // Create worker processes
    /*insert code here*/
    for(i=0; i<n_procs; i++){
        if(fork() == 0){
            printf("Worker %d created and ready!\n", getpid());
            worker();
            printf("Worker %d leaving\n", getpid());
            exit(0);
        }
    }
 
    // Wait for all worker processes
    /*insert code here*/
    for (i = 0; i < n_procs; i++) wait(NULL);
 
    // print final result
    /*insert code here*/
    printf("Final Result: %d\n", *shared_var);
 
    // remove resources (shared memory and semaphores)
    /*insert code here*/
    sem_close(semid);
    shmdt(shared_var);
    shmctl(shmid, IPC_RMID, NULL);
 
    exit(0);
}