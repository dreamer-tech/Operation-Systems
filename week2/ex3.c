#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 2 * n; j++) {
            if (j >= n - i && j <= n + i)
                printf("*");
            else 
                printf(" ");
            }
        printf("\n");
    }
}
