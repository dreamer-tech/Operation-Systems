#include <stdio.h>
#include <string.h>

void triangle (int n) {
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

void square (int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("*");
        printf("\n");
    }
}

void reversed_triangle (int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j < 2 * n; j++) {
            if (j >= n - i && j <= n + i)
                printf("*");
            else 
                printf(" ");
            }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Enter figure number (1 - triangle; 2 - square; 3 - reversed triangle)");
    scanf("%d", &choice);
    int n;
    scanf("%d", &n);
    if (choice == 1)
        triangle(n);
    if (choice == 2)
        square(n);
    if (choice == 3)
        reversed_triangle(n);
}

