#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < 5; i++) {
        int temp = counter;     // read
        temp++;                 // modify
        sleep(1);               // force context switch
        counter = temp;         // write

        printf("Thread %ld: %d\n", (long)arg, counter);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, (void*)1);
    pthread_create(&t2, NULL, increment, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter = %d\n", counter);
    return 0;
}

