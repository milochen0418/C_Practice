#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>


#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>

/*
// The following code is what windows do
#include <conio.h>
printf("please press P key to pause \n ");
int key = 0;
while(1) {
    if (_kbhit()) {
      key =_getch();
      if (key == 'P')
        break;
    }
}

*/


int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;
    if (! initialized) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }
    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}


void test_keyboard() {
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    printf("Press any key");
    int bufferCnt;
    while(1) {
    	if(bufferCnt = _kbhit()) {
    		if(bufferCnt == 3) {
    			char byte1 = getch();
    			char byte2 = getch();
    			char byte3 = getch();
    			printf("\r\n%02d, %02d, %02d\r\n", byte1, byte2, byte3);
    		}
    		else if(bufferCnt == 2) {
    			char byte1 = getch();
    			char byte2 = getch();
    			printf("\r\n%02x, %02x\r\n", byte1, byte2);
    		}
    		else {
	    		char ch = getch();
	    		printf("\r\n\nKBHIT()!%d - %c(%02x)\n\n\r", bufferCnt, ch, ch);
    		}	
    		fflush(stdout);
    	}
    	else {
	        printf(".");
    	    fflush(stdout);
			usleep(1000* 100);
    	}
    }
    printf("\r\n end of kbhit_test2()\r\n");
}



int main() {
    test_keyboard();
	printf("\r\n end\r\n");
	return 0;
}
