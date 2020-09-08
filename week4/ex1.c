#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int arg, char *argv[]) {

    int res = fork();

    if (res == -1)
        printf("Fork failed. It's a pity:(");
    else if (res == 0)
        printf("Hello from child [%d - %d]\n", getpid(), res);
    else if (res > 0)
        printf("Hello from parent [%d - %d]\n", getpid(), res);
    return 0;
}

/*
 We run this script using shell file - ex1.sh
 According to the fork returning value we either print 'Hello from child' or 'Hello from parent'
 Fork returns -1, if it failed
               0, if it has created successfully
               else, ID of newly created child process
 */
