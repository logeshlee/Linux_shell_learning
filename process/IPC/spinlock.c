#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_spinlock_t spin;
int counter = 0;

void* worker(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_spin_lock(&spin);
        counter++;
        printf("Thread %ld: %d\n", (long)arg, counter);
        pthread_spin_unlock(&spin);
        usleep(100000);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_spin_init(&spin, PTHREAD_PROCESS_PRIVATE);

    pthread_create(&t1, NULL, worker, (void*)1);
    pthread_create(&t2, NULL, worker, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_spin_destroy(&spin);
    return 0;
}

