#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child
        printf("Child: PID=%d, PPID=%d\n", getpid(), getppid());
        sleep(2);
        printf("Child exiting\n");
    } else {
        // Parent
        int status;
        printf("Parent: PID=%d, waiting for child %d\n", getpid(), pid);
        wait(&status);
        printf("Parent: child finished\n");
    }
    return 0;
}

