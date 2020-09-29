#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int main() {
    int n, i;

    // prompt the user to enter N
    printf("Enter the size of an array: ");
    scanf("%d", &n);

    //  allocate memory for an array of N integers
    int *arr = malloc(n * sizeof(int));

    // fills the array with incremental values starting from 0
    for (i = 0; i < n; i++)
        arr[i] = i;

    // print the array
    printf("\nInitialized array\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // deallocate the memory
    free(arr);
    return 0;
}
