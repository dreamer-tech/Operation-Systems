#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>


int main() {
	errno = 0;
	DIR *dir = opendir("tmp/");
	struct dirent *dent;
	struct stat st;
	char full_name[1024];
	FILE *fp = fopen("ex4.txt", "w");
	while ((dent = readdir(dir)) != NULL) {
		snprintf(full_name, sizeof(full_name), "%s%s", "tmp/", dent->d_name); 
		if (st.st_nlink >= 2) {
			fprintf(fp, "%s\n", full_name);
		}
	}
	return 0;
}
