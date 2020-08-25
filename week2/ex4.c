#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int a, b;
    printf("Enter please 2 integer numbers: ");
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
}
