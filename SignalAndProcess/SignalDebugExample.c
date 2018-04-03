#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


/*
After compile this code. 
execute it 
and then use the following command
$ kill -SIGUSR1 $PID

(use command [$ ps x]  to find the PID)


then , again ... 
$ kill -SIGUSR1 $PID

So you can see what happen 
*/
int debug=1;

void MySIGUSR1(int sig)
{
   printf("got signal %d\n", sig);
	debug = !debug;
   printf("toggle debug message");
	if(!debug) {
		printf("Debug message is disable\n");
	}
	else {
		printf("Debug message is enable\n");
	}
}

int main(int argc, char *argv[])
{
    signal(SIGUSR1, MySIGUSR1);
    
    while(1) {
		if(debug)
        	printf("Hello World!\n");

        sleep(1);
    }

	exit(0);
}

