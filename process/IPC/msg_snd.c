#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg message;
    message.type = 1;
    strcpy(message.text, "Hello from sender");

    msgsnd(msgid, &message, sizeof(message.text), 0);
    printf("Message sent\n");

    return 0;
}

