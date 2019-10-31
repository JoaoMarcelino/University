#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t id;
	pid_t childpid=fork();
	if (childpid==0){
		for(int i=0;i<3;i++){
			id=fork();
			if (id!=0){
				wait(NULL);
				printf("I am %ld,my father is %ld\n",(long)getpid(),(long)getppid());
				exit(0);
			}
		}
	}
	else{
		wait(NULL);
		printf("I am %ld, the original\n",(long)getpid());
		exit(0);
	}
}