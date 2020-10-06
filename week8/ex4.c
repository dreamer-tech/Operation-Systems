#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>


int main() {
    int i;
    struct rusage usg;
    for (i = 0; i < 10; i++) {
        int sz = 10 * 1024 * 1024;  // 10 MB
        void *mem = malloc(sz);  // allocate 10 MB
        memset(mem, 0, sz);  // fill it with zeros
        getrusage(RUSAGE_SELF, &usg);
        printf("%ldKB\n", usg.ru_maxrss);  // print memory usage
        sleep(1);
    }
    return 0;
}
