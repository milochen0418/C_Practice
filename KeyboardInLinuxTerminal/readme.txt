
My develop system is in 
Ubuntu 14.04.5 32-bits
The way to build main.c in linux 

$ apt-get install libncurses5-dev
$ gcc main_snake.c -L/usr/lib/i386-linux-gnu/ -lncurses -I/usr/include/i386-linux-gnu -o a.out


// build for termios, ioctl to make _kbhit like function

