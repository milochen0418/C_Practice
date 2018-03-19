/* 
typedef and struct
struct book{ float value};
struct book mybook;
struct book* ptr;
typedef struct book BOOKS; //BOOKS mybook;
typedef BOOKS* pBooks; //=> pBooks ptr;

typedef struct BookStore {
	float value;
} BOOKS_STORE;


enum spectrum {RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET};
enum BOOL {FALSE, TRUE};
enum spectrum color;
int color = BLUE;


*/

#include <stdio.h> 

struct book{ 
	float value;
};
struct book mybook;
struct book* ptr;
typedef struct book BOOKS; //BOOKS mybook;
typedef BOOKS* pBooks; //=> pBooks ptr;

typedef struct BookStore {
	float value;
} BOOKS_STORE;


enum spectrum {RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET};
enum BOOL {FALSE, TRUE};
enum spectrum color;
int color2 = BLUE;

int main() {

}