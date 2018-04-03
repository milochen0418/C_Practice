#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
/*
	Write a program to accept argument n such that the program can generate n process.
	Please show PID and PPID for each process. so that it can help to debug
*/
int main(int argc, char *argv[])
{
    pid_t pid;
    char message[100];

	 pid_t pids[100];
    int n;
	
	
   printf("start: ppid=%d \t pid=%d \n", getppid(), getpid());
	if(argc>1) {
		n = atoi(argv[1]);
		int i;	
		for ( i = 0; i < n ; i++ ) {
			int new_pid = fork();
			if(new_pid == 0) { 
				//this is code for new process
   			//printf("child start: ppid=%d \t pid=%d \n", getppid(), getpid());
				break;
			}
			else {
				if(new_pid > 0) {
					pids[i] = new_pid;
   				printf("ppid=%d \t pid=%d \n", getpid(), pids[i]);
				}
			}
		}
	}

	exit(0);
}

