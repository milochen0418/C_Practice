#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void ouch(int sig)
{
	printf("ouch: got signal %d\n", sig);
}

void old_ouch(int sig) {

	printf("old_ouch : got signal %d\n", sig);
}
typedef void (*sighandler_t)(int);


int main(int argc, char *argv[])
{

	signal(SIGINT, old_ouch);
	sighandler_t ret_handler = signal(SIGINT, ouch);
    
	while(1) {
		printf("Hello World!\n");
		sleep(1);
		ret_handler(SIGINT);
	} 
	exit(0);
}

