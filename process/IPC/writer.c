#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo = "/tmp/myfifo";
   // mkfifo(fifo, 0666); // create named pipe

    int fd = open(fifo, O_WRONLY);
    char msg[] = "Hello from writer!";
    write(fd, msg, strlen(msg) + 1);
    close(fd);

    return 0;
}

