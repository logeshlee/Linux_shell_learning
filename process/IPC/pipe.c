#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];  // fd[0] = read end, fd[1] = write end
    pid_t pid;
    char buffer[100];

    pipe(fd);       // create pipe
    pid = fork();   // create child process

    if (pid == 0) {
        // Child Process - Reader
        close(fd[1]);  // close write end
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {
        // Parent Process - Writer
        close(fd[0]);  // close read end
        char msg[] = "Hello from parent";
        write(fd[1], msg, strlen(msg) + 1);  // include null byte
        close(fd[1]);
    }

    return 0;
}

