#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg message;
    msgrcv(msgid, &message, sizeof(message.text), 1, 0);

    printf("Received: %s\n", message.text);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

