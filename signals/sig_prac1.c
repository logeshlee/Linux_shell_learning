#ifndef HEAD
#define HEAD
#include<stdio.h> //main
#include <stdlib.h>
#include<unistd.h> //pause(), write()
#include<signal.h> //sigaction, signals
#endif

void myhandler(int sig) {
    printf("Caught signal %d\n", sig);
}
void myhandler1(int sig, siginfo_t*info, void*uncontext) {
    char msg[] = "Signal received, terminating...\n";
    write(1, msg, sizeof(msg));
    exit(0);
}

int main(){


    struct sigaction sa; //defined in signals
//    sa.sa_handler = myhandler;
    sa.sa_sigaction = myhandler1;
    sigemptyset(&sa.sa_mask); //create a set of empty set of signals and init
    sigaddset(&sa.sa_mask, SIGINT);  //add sigint to set if need more repeat the function
    sa.sa_flags = SA_RESTART|SA_SIGINFO; //use sigaction handler instead of basic handeler
    pid_t mypid = getpid();
    sigaction(SIGINT, &sa, NULL);

    while(1);


}
