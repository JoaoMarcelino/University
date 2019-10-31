/******************************************************************************
* FILE: shop.c
* DESCRIPTION:
*   A shop has several moneyiers and one foreman, each represented by a thread. 
*   The threads are created by the main thread.
*   - Some threads represent the shop employees that sell items for 10 eur
*     and put the money in a common safe.
*   - One thread represents the foreman that watches the value of the money. When it 
*     reaches a predefined limit (CASH_LIMIT), he removes an amount of CASH_LIMIT
*     money from the safe, for security reasons.
*   - The program ends after NSALES
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS  8	// Total number of threads (>1)
#define NSALES 30	// Max number of sales made by all employees
#define CASH_LIMIT 50	// Limit of the 'count' variable before it is reset 

int   sales = 0;
int		money = 0;

/* initialize money_mutex and money_amount_cv condition variable */

// ...... insert code here .......

void *employee(void *t)
{
  int my_id = *((int *)t);
  
  printf("Starting employee(): thread %d\n", my_id);

  while (1) {

	/* If sales < NSALES make a sell and put money in the safe
	   else exits thread */

	// ...... insert code here .......

	}

  pthread_exit(NULL);
}

void *foreman(void *t) 
{
  int my_id = *((int *)t);

  printf("Starting foreman(): thread %d\n", my_id);

  while (1) {

	/* wait if money<CASH_LIMIT and sales<NSALES
	   when sales >= NSALES exit thread */
 	
	// ...... insert code here .......

	}
 
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  int i; 
  int id[NUM_THREADS];
  pthread_t threads[NUM_THREADS];

  /* Create threads */

  // ...... insert code here .......

  /* Wait for all threads to complete */

  // ...... insert code here .......

  printf ("Main(): Waited and joined with %d threads. Final money in safe = %d. Done!\n", 
          NUM_THREADS, money);

  /* Clean up and exit */

  // ...... insert code here .......

}
