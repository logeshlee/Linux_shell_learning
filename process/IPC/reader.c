#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    char buffer[100];

    mkfifo(fifo, 0666); // create named pipe if not exists
    int fd = open(fifo, O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("Reader got: %s\n", buffer);
    close(fd);

    return 0;
}

