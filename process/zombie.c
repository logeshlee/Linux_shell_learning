#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child
        printf("Child exiting\n");
        return 0;
    } else {
        // Parent does NOT call wait()
        printf("Parent sleeping, child PID=%d\n", pid);
        sleep(30);
    }
    return 0;
}

