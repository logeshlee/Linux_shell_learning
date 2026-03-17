#include <stdio.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        sleep(30);   // long sleep
        printf("Child: PID=%d PPID=%d\n", getpid(), getppid());
    } else {
        printf("parent: PID=%d PPID=%d\n", getpid(), getppid());
        _exit(0);     // parent dies immediately
    }
}

