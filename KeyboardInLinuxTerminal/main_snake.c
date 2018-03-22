#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>


#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>

#include <assert.h>

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

typedef struct _MiPos{
	int x;
	int y;
} MiPos ;

typedef enum _MiDrawType{
	MI_SNAKE_HEAD,
	MI_SNAKE_BODY,
	MI_SNAKE_FOOD,
	MI_GAME_BOUND,
	MI_GAME_EMPTY,
} MiDrawType; 

#define GAME_AREA_HEIGHT (30)
#define GAME_AREA_WIDTH (120)
#define GAME_PLANE_HEIGHT (GAME_AREA_HEIGHT+2*GAME_BOUND_SIZE)
#define GAME_PLANE_WIDTH (GAME_AREA_WIDTH+2*GAME_BOUND_SIZE)
#define GAME_BOUND_SIZE (1)
static MiDrawType game_plane[GAME_PLANE_HEIGHT][GAME_PLANE_WIDTH];

void game_plane_draw_empty ();
void game_area_draw_point (MiPos pos, MiDrawType draw_type);
void game_area_clean ();
void game_plane_init ();
void game_area_draw_point (MiPos pos, MiDrawType draw_type);




void snake_loop(int kbhit_buf_size, char* buf, int* isExit);
GameKey snake_input_process(int kbhit_buf_size, char* buf);


void snake_game_viewshow() {
	//view show is process to show the data in the terminal
	//or any GUI according to the data in model game_plane;

	system("clear");
	int i,j;
	for (i = 0; i < GAME_PLANE_HEIGHT; i++) {
		for (j = 0; j < GAME_PLANE_WIDTH; j++) {
			MiDrawType type = game_plane[i][j];
			char ch;
			switch(type) {
				case MI_GAME_BOUND:
					ch = '+';
				break;
				case MI_GAME_EMPTY:
					ch = ' ';
				break;
				case MI_SNAKE_FOOD:
					ch = '*';
				break;
				case MI_SNAKE_BODY:
					ch = '+';
				break;
				case MI_SNAKE_HEAD:
					ch = 'o';
				break;
			}
			printf("%c", ch);
		}
		printf("\n\r");
	}
	fflush(stdout);

}





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
	static MiPos prev_head_pos = {3,3};
	static MiPos head_pos = {3,3};

	switch(key) {
		case GK_QUIT:
			//printf(" Q ");		
			*isExit = TRUE;
			break;
		case GK_UP:
			//printf(" U ");
			prev_head_pos = head_pos;
			head_pos.y -=1;
			break;
		case GK_RIGHT:
			//printf(" R ");
			prev_head_pos = head_pos;
			head_pos.x +=1;
			break;
		case GK_LEFT:
			//printf(" L ");
			prev_head_pos = head_pos;
			head_pos.x -=1;
			break;
		case GK_DOWN:
			//printf(" D ");
			prev_head_pos = head_pos;
			head_pos.y +=1;
			break;
		case GK_NOKEY:
		default:
			break;		
	}
	
	

	if(key != GK_NOKEY) {
		//fflush(stdout);
		snake_game_viewshow();
	} 
	else {
		//printf(".");
		game_area_draw_point(prev_head_pos,MI_GAME_EMPTY);
		game_area_draw_point(head_pos,MI_SNAKE_HEAD);

		snake_game_viewshow();
		//fflush(stdout);
	}
	usleep(1000 * 20);
}


void play_snake(){

	game_plane_init();	


	/* initial code for keyboard */
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



void game_area_clean () {
	game_plane_draw_empty();
}

void game_plane_init () {
	game_plane_draw_empty();
} //end of game_plane_init()

void game_plane_draw_empty () {
	//draw function is draw game_plane
	//and you can see the final result after you call the view show
	int i;
	int j;
	int w = GAME_PLANE_WIDTH;  //snake is play in game area
	int h = GAME_PLANE_HEIGHT;
	int b = GAME_BOUND_SIZE;
	//draw bound of the plane into model
	for ( i = 0; i < h; i++) {
		for (j = 0; j < w ; j++) {
			if( (i<b) || (j<b) || (i>=h-b) || (j>=w-b) ) {
				game_plane[i][j] = MI_GAME_BOUND; //draw bound in frame
			}
			else {
				game_plane[i][j] = MI_GAME_EMPTY; //draw game_area to empty
 			}
		}
	}	
} //game_plane_draw_empty()


void game_area_draw_point (MiPos pos, MiDrawType draw_type) {
	assert(pos.x >= 0 && pos.y >= 0 && pos.x < GAME_AREA_WIDTH && pos.y < GAME_AREA_HEIGHT);
	assert(draw_type!=MI_GAME_BOUND);
	game_plane[pos.y+1][pos.x+1] = draw_type;
} 

