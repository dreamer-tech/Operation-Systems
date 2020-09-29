#include <stdio.h>
#include <stdlib.h>


int main() {
    // is okay
    char **s;

    // is okay
    char foo[] = "Hello World";

    // have to allocate memory first
    s = malloc(sizeof(char *));
    *s = foo;

    // have to add '*' before s, as we want to print the string itself
    printf("s is %s\n", *s);

    // is okay
    s[0] = foo;

    // is okay
    printf("s[0] is %s\n", s[0]);
    return 0;
}

