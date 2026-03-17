#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;
int counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        printf("Thread %ld: %d\n", (long)arg, counter);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, (void*)1);
    pthread_create(&t2, NULL, increment, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}

