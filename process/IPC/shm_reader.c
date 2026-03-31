#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65);             // same key
    int shmid = shmget(key, 1024, 0666);         // get shm segment

    char *str = (char *) shmat(shmid, NULL, 0);  // attach
    printf("Reader got: %s\n", str);
    shmdt(str);                                  // detach
    shmctl(shmid, IPC_RMID, NULL);               // remove segment
    return 0;
}

