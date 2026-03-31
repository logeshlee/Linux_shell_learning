#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>

union semun { int val; };

int main() {
    key_t key = ftok("file", 75);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = shmat(shmid, NULL, 0);

    int semid = semget(key, 1, 0666 | IPC_CREAT);
    union semun u;
    u.val = 1;  // binary semaphore init to 1
    semctl(semid, 0, SETVAL, u);

    struct sembuf p = {0, -1, 0};  // lock
    semop(semid, &p, 1);

    strcpy(str, "Hello protected");
    
    struct sembuf v = {0, 1, 0};   // unlock
    semop(semid, &v, 1);

    shmdt(str);
    return 0;
}

