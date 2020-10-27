#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main() {
    printf("Hello\n");
    fork();
    printf("\n");
    return 0;
}
