#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65);               // generate unique key
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); // create shm segment

    char *str = (char *) shmat(shmid, NULL, 0);    // attach to memory
    strcpy(str, "Shared Hello!");
    shmdt(str);                                    // detach
    return 0;
}

