#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

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
int main() {

	ncurses_getch_test();
	
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    while (true) {
        if (getch() == 'g') {
            printw("You pressed G\n");
        }
        napms(50);
        printw("Running\n");
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
