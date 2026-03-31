#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal: %d\n", sig);
}

int main() {
    for (int i = 1; i < 32; i++) {
        signal(i, handler);  // attach handler to all signals
    }
    while (1) {
        pause(); // wait for signal
    }
    return 0;
}

