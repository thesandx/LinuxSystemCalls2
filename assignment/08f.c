#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include<sys/time.h>
#include <stdbool.h>


volatile sig_atomic_t print_flag = false;

void signal_handler(int signal_no){
    print_flag = true;
    printf("Caught the SIGVTALRM signal\n");
   
}

int main(int argc,char const *argv[]){

     struct itimerval timer;

    timer.it_value.tv_sec=1;
    timer.it_value.tv_usec = 1;
    timer.it_interval = timer.it_value ;

    
    //printf("Timer set successfully.\n");

     if(signal(SIGVTALRM,signal_handler)==SIG_ERR){
        perror("Error ");
    }

    
   // alarm(1);
   // raise(SIGALRM);

    setitimer(ITIMER_VIRTUAL,&timer,NULL);
    for (;;) {
        if(print_flag==true){
            break;
        }
    }


    return 0;
}