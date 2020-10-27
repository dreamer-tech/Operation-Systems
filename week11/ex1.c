#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>


int main() {
    struct stat buffer;

    int fd = open("ex1.txt", O_RDWR);

    // get file status
    if (fstat(fd, &buffer)) {
        printf("Cannot get file status");
        return 0;
    }

    // mmap the file
    char *addr = mmap(NULL, buffer.st_size, PROT_WRITE, MAP_SHARED, fd, 0);

    // write needed string to the file
    strncpy(addr, "This is a nice day", buffer.st_size);

    // return
    munmap(addr, buffer.st_size);

    // close file
    close(fd);
    return 0;
}
