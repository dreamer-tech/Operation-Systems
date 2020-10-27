#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main() {
	printf("H%c", 10);
	sleep(1);
	printf("e%c", 10);
	sleep(1);
	printf("l%c", 10);
	sleep(1);
	printf("l%c", 10);
	sleep(1);
	printf("o%c", 10);
	sleep(1);	
	return 0;
}
