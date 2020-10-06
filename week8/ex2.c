#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    int i;
    for (i = 0; i < 10; i++) {
        int sz = 10 * 1024 * 1024;  // 10 MB
        void *mem = malloc(sz);  // allocate 10 MB
        memset(mem, 0, sz);  // fill it with zeros
        sleep(1);
    }
    return 0;
}

// running this code in background eventually increase 'si' and 'so' params when we write command 'vmstat 1'
