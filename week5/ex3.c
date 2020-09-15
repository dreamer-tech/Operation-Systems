#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAXN 228 * 1337  // logically it should be a constant but unfortunately it's C :-(
#define SLEEP_TIME 1  // logically it should be a constant but unfortunately it's C :-(

int buffer_top = 0, nxt_number = 0, buffer[MAXN];
pthread_mutex_t mutex;
pthread_cond_t condition;

void *producer_thread(void *id) {
    while (228) {

        // Lock the mutex
        pthread_mutex_lock(&mutex);

        while (buffer_top >= MAXN) {
            pthread_cond_wait(&condition, &mutex);
        }

        buffer[buffer_top++] = nxt_number;
        printf("Just produced %d\n", nxt_number++);

        sleep(SLEEP_TIME);

        pthread_cond_broadcast(&condition);  // send signal
        pthread_mutex_unlock(&mutex);  // release lock
    }
    return NULL;
}


void *consumer_thread(void *id) {
    while (1337) {

        // Lock the mutex
        pthread_mutex_lock(&mutex);

        while (buffer_top <= 0) {
            pthread_cond_wait(&condition, &mutex);
        }

        printf("Just consumed %d\n", buffer[--buffer_top]);

        sleep(SLEEP_TIME);

        pthread_cond_broadcast(&condition);  // send signal
        pthread_mutex_unlock(&mutex);  // release lock
    }
    return NULL;
}


int main() {

    pthread_t producer, consumer;

    // Initialize mutex and condition
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);

    // Create threads
    pthread_create(&producer, NULL, producer_thread, (void *)&producer);
    pthread_create(&consumer, NULL, consumer_thread, (void *)&consumer);

    // Join consumer and producer
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    return 0;
}
