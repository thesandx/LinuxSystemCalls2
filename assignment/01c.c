#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include<sys/time.h>

int main(int argc,char const *argv[]){


    struct itimerval timer;

    timer.it_value.tv_sec=10;
    timer.it_value.tv_usec = 10;
    timer.it_interval = timer.it_value ;

    setitimer(ITIMER_PROF,&timer,NULL);
    printf("Timer set successfully.\n");
    while(1); 
    return 0;
}