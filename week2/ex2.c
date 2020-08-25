#include <stdio.h>
#include <string.h>

int main() {
    char s[1024];
    printf ("Please enter a string: ");
    gets(s);
    char result[1024];
    for (int i = strlen(s) - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
}
