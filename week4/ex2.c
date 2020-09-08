#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int arg, char *argv[]) {

    for (int i = 0; i < 3; i++) {
        fork();
        sleep(5);
    }
    return 0;
}

/*
 If I run script 3 times and see on the output of pstree, then it will the following
 1) ex2---ex2
 2) ex2---ex2---ex2
        |-ex2
 3) ex2---ex2---ex2---ex2
        |     |-ex2
        |-ex2---ex2
        |-ex2
 So total 2^n processes were created, in our case = 2^3 = 8. In the diagram above it's clearly seen which process fork new one and how many times.

 For n = 5, the diagram will be much bigger so I won't draw it, but it's obvious it will be 2^5 = 32 processes

 P.S. When we make a call 'fork' it creates new child process the will continue executing program straight after the line where it was created (line following 'fork' call)
 */
