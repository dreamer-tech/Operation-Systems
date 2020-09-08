#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int arg, char *argv[]) {
    const int SZ = 1024;
    char command[SZ];
    printf("It is a simplistic shell\n");
    printf("Write commands and they will be executed automatically\n");
    printf("If you want to finish the execution, then just write 'finish'\n\n");
    printf("Enter new command\n");
    while (gets(command)) {
        if (strcmp(command, "finish") == 0)
            break;
        system(command);
        printf("Enter new command again\n");
    }
    return 0;
}
