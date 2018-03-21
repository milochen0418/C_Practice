#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>


#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>


#define TRUE 1
#define FALSE 0

int _kbhit();
void test_keyboard();

void play_snake();
typedef enum {
	GK_UP,
	GK_DOWN,
	GK_LEFT,
	GK_RIGHT,
	GK_QUIT,
	GK_NOKEY
} GameKey;

void snake_loop(int kbhit_buf_size, char* buf, int* isExit);
GameKey snake_input_process(int kbhit_buf_size, char* buf);







int main() {
    //test_keyboard();
    play_snake();
	printf("\r\n end\r\n");
	return 0;
}

void snake_loop(int kbhit_buf_size, char* buf, int* isExit) {
	GameKey key = snake_input_process(kbhit_buf_size, buf);
	/*
		GameKey is final result of input, so there is no depdency on 
		any type of keyboard scan code ... just need to focus on game
	*/

	switch(key) {
		case GK_QUIT:
			printf(" Q ");		
			*isExit = TRUE;
			break;
		case GK_UP:
			printf(" U ");
			break;
		case GK_RIGHT:
			printf(" R ");
			break;
		case GK_LEFT:
			printf(" L ");
			break;
		case GK_DOWN:
			printf(" D ");
			break;
		case GK_NOKEY:
		default:
			break;		
	}

	if(key != GK_NOKEY) {
		fflush(stdout);
	} 
	else {
		usleep(1000 * 20);
		printf(".");
		fflush(stdout);
	}
}


void play_snake(){
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    printf("Press any key");
    int bufferCnt;
    char buf[20];
    int isExit = FALSE;
    int i = 0;

    while(1) {
    	/* setup input for snake_loop*/
		bufferCnt = _kbhit();
		if(bufferCnt > 20) bufferCnt = 20;
		for ( i = 0; i < bufferCnt ;i++) {
			buf[i] = getch();
		}

		snake_loop(bufferCnt, buf, &isExit);
		if(isExit) break;
    }
	printf("\r\n end of play_snake()\r\n");
}




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

GameKey snake_input_process(int kbhit_buf_size, char* buf) {
	GameKey key = GK_NOKEY; 
	char ch;
	switch(kbhit_buf_size) {
		case 1:
			ch = buf[0];
			if(ch == 'a' || ch == 'A') {
				key = GK_LEFT;
			} 
			else if (ch == 'w' || ch == 'W'){
				key = GK_UP;
			} 
			else if (ch == 's' || ch == 'S'){
				key = GK_DOWN;
			}
			else if (ch == 'd' || ch == 'D'){
				key = GK_RIGHT;
			}
			else if (ch == 'q' || ch == 'Q'){
				key = GK_QUIT;
			}
		default:
		break;
	}	
	return key;
}


/* when you want to change up,down,left,right key 
you will use this function to get scan code of them in future 
*/
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
    printf("\r\n end of test_keyboard()\r\n");
}



