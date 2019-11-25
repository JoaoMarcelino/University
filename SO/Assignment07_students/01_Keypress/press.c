#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int t_ini,num;

/* Create the function that handles CTRL-Z */
void sigint(int signum){
	int counter =time(NULL)-t_ini;
	if (counter<num)
		printf("Too Fast, slow down \n");
	else if(counter>num)
		printf("Too Slow, keep up\n");
	else
		printf("You can count, Hurray,your mom must be proud\n");
}

/* function end */

/* Create the function that handles CTRL-C */


/* function end */

int main()
{
  /* Redirect signals */
	signal(SIGINT, sigint);


  // Do some work!
  srand(time(NULL));

  /* Ignore the SIGINT (CTRL-C) */
  signal(SIGINT,SIG_IGN);

  /* End ignore */
  //signal(SIGINT,SIG_DFL);
  
  while (1) {
	num=rand()%8+2;
	printf("\n\nPress CTRL-C in %d seconds!\nCountdown starting in 2 seconds... Get Ready!!\n",num);
	sleep(2);
	/* Redirects the SIGINT again */
	signal(SIGINT,sigint);
	/* End redirect */

	printf("Start counting the seconds!!\n");
	t_ini=time(NULL);
    	pause();
	}
  return 0;
}

