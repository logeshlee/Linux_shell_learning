#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child exiting\n");
        return 0;
    } else {
        wait(NULL);
        printf("Parent cleaned child\n");
    }
    return 0;
}

