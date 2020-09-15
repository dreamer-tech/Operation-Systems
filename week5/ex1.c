#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *thread(void *id) {
    int *my_id = (int *)id;
    printf("Hey, I am in Thread %d!\n", *my_id);
    return NULL;
}


int main() {

    const int N = 10;  // total number of threads
    int i;
    for (i = 1; i <= N; i++) {
        pthread_t thread_id;
        printf("Create Thread %d\n", i);
        pthread_create(&thread_id, NULL, thread, (void *)&i);  // create a thread
        pthread_join(thread_id, NULL);  // join a thread to create them sequentially
        printf("Exit out of Thread %d\n", i);
    }

    return 0;
}
// If we remove the pthread_join then all messages will be mixed up, they will be printed randomly
// Like:
//  - Create Thread 1
//  - Create Thread 2
//  - Hey, I am in Thread 1
//  - Create Thread 3
//  - Exit out of Thread 1
//  and so on...
// Joining a thread allows us to make it like a common function - we can't go further until thread finishes its work
// After joining the Output looks like:
//  - Create Thread i
//  - Hey, I am in Thread i
//  - Exit out of Thread i
//  - Create Thread i + 1
//  ...
