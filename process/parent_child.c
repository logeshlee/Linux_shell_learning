 #include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        // fork failed
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child: PID=%d, PPID=%d\n", getpid(), getppid());
        sleep(4);
    } else {
        // Parent process

        waitpid(pid, NULL, WNOHANG);
        printf("Parent: PID=%d, Child PID=%d\n", getpid(), pid);
    }

    return 0;
}

