#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child replaces itself
        execlp("ls", "ls", "-l", NULL);
        // exec only returns on error
        perror("exec failed");
    } else {
        printf("Parent: PID=%d, child PID=%d\n", getpid(), pid);
        sleep(1);
    }
    return 0;
}

