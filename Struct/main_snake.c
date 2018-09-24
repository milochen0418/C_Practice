#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

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
#define SNACK_MAX_LEN 100
#if 0
typedef struct MiBody {
	int row;
	int col;
} _body;

typedef struct MiSnack {
	body bodys[SNACK_MAX_LEN];
	int len;
};
typedef enum MiDir {
	UP,DOWN,LEFT,UP
} _MiDir;

MiSnack snack;

void snack_init();
void snack_move(_MiDir dir);

void update_view();

#endif

#include <unistd.h>

#if 1
//kbhit http://www.flipcode.com/archives/_kbhit_for_Linux.shtml
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>


void ncurses_getch_test() {
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    while (true) {
        if (getch() == 'g') {
            printw("You pressed G\n");

        }
        napms(500);
        printw("Running\n");
    }	
}


int _kbhit() {
    static const int STDIN = 0;
    static bool initialized = false;
    if (! initialized) {
        // Use termios to turn off line buffering
        //termios term;
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


void kbhit_test() {
    printf("Press any key");
    while (! _kbhit()) {
        printf(".");
        fflush(stdout);

        usleep(1000* 100);
    }
    printf("\nDone.\n");
    return;
}
void kbhit_test2() {
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
#endif 


int main() {
	kbhit_test2();
	printf("\r\n end\r\n");
	return 0;
	//ncurses_getch_test();

    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    int i;
    static char p[1000];
    while (true) {
        if (getch() == 'g') {
        	sprintf(p,"%d\n", i);
            //printw("You pressed G\n");
            printw(p);
            
        }
        napms(50);
        i++;
        //printw("Running\n");
    }	
	/*
	while(1) {
		update_view();
		sleep(1);
		//usleep(3000);
	};
	*/

	//getch(), kbhit()

}

#if 0
void update_view() {
	system("clear");
	printf("■□\n");
}


#endif
