#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("file", 75);
    int shmid = shmget(key, 1024, 0666);
    char *str = shmat(shmid, NULL, 0);

    int semid = semget(key, 1, 0666);

    struct sembuf p = {0, -1, 0};  // lock
    semop(semid, &p, 1);

    printf("Reader: %s\n", str);

    struct sembuf v = {0, 1, 0};  // unlock
    semop(semid, &v, 1);

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
    return 0;
}

