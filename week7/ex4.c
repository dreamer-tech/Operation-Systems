#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void *my_own_realloc(void *ptr, size_t sz) {
    if (ptr == NULL)
        // just allocate memory
        return malloc(sz);
    if (sz == 0) {
        // release memory
        free(ptr);
        return NULL;
    }
    // create new array
    int *new_arr = malloc(sz);
    // copy old values
    memcpy(new_arr, (int *)ptr, sz);
    // release previous array
    free(ptr);
    return new_arr;
}


int main() {

    int i;

    printf("Initial Array: ");
    int *arr = calloc(5, sizeof(int));
    for (i = 0; i < 5; i++)
        printf("%d ", *(arr + i));
    printf("\n");

    printf("If we decrease the size of an array: ");
    arr = my_own_realloc(arr, 3 * sizeof(int));
    for (i = 0; i < 3; i++)
        printf("%d ", *(arr + i));
    printf("\n");

    printf("If we increase the size of an array: ");
    arr = my_own_realloc(arr, 7 * sizeof(int));
    for (i = 0; i < 7; i++)
        printf("%d ", *(arr + i));
    printf("\n");

    printf("If we want to free memory\n");
    arr = my_own_realloc(arr, 0);

    printf("Final call: ");
    arr = my_own_realloc(NULL, 5 * sizeof(int));
    for (i = 0; i < 5; i++)
        printf("%d ", *(arr + i));
    printf("\n");

    return 0;
}

