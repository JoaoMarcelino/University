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

#define N_NEWSTEAMS 10
#define EXAMPLE_NEWS 5
#define NEWS_MAX_SIZE 30

int main_pid;
int pipes[N_NEWSTEAMS][2];
char example_news[EXAMPLE_NEWS][NEWS_MAX_SIZE] = {
	"All about the money",
	"food for the soul", 
	"home team wins", 
	"an amazing discovery", 
	"newest tec came out"
};

typedef struct _news{
	int team;
	char newsText[NEWS_MAX_SIZE];
} news;

news news_data;

void sigint(int signum){
	/* bruh */
	for(int i = 0; i<N_NEWSTEAMS; i++){
		close(pipes[i][0]);
		close(pipes[i][1]);
	}

	exit(0);
}

//Code run by NEWSTEAMS
void newsTeam(int channel[],int i){
	news_data.team = i;
	srand(i);
	signal(SIGINT,sigint);
	close(channel[0]);
	while(1){
		strcpy(news_data.newsText, example_news[rand() % EXAMPLE_NEWS]);
		printf("News team %d Submitting news: \"%s\" \n", news_data.team, news_data.newsText);
		write(channel[1], &(news_data.newsText),NEWS_MAX_SIZE);
		sleep((rand() % 2)+1);
	}
}

int main(){
	main_pid = getpid();
	signal(SIGINT,SIG_IGN);
	for(int j = 0; j<N_NEWSTEAMS;j++){
		pipe(pipes[j]);
	}
	for(int i = 0; i< N_NEWSTEAMS; i++){
		if ((main_pid = fork()) == 0){
			newsTeam(pipes[i],i);
		}
		close(pipes[i][1]);
	}

	//Editor
	fd_set read_set;
	int r=0;
	char text[NEWS_MAX_SIZE];
	signal(SIGINT,sigint);
	FD_ZERO(&read_set);
	while(1){
		for(int i = 0; i<N_NEWSTEAMS;i++){
			if ((r=rand()%10)<=1){
				read(pipes[i][0],&text,NEWS_MAX_SIZE);
				printf("Breaking News %d: \"%s\"\n",r,text);
			}
		}
	}
	return 0;
}
