#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int sz) {
    int i, j;
    for (i = 0; i < sz; i++) {
        for (j = 0; j < sz - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int tmp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = tmp;
            }
        }
    }
}

int main() {
    const int sz = rand() % 100;
    int i, arr[sz];
    for (i = 0; i < sz; i++)
        arr[i] = rand() % 100;
    for (i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    bubble_sort(arr, sz);
    printf("\n");
    for (i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    return 0;
}
