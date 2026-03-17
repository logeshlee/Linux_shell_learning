#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        if (fork() == 0) {
            sleep(i + 1);
            printf("Child %d exiting\n", getpid());
            return 0;
        }
    }

    int status;
    while (waitpid(-1, &status, 0) > 0) {
        printf("Parent collected a child\n");
    }
    return 0;
}

