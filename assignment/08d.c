#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include <stdbool.h>


volatile sig_atomic_t print_flag = false;

void signal_handler(int signal_no){
    print_flag = true;
    printf("Caught the SIGALRM signal\n");
   
}

int main(int argc,char const *argv[]){

     if(signal(SIGALRM,signal_handler)==SIG_ERR){
        perror("Error ");
    }

    alarm(1);

    for (;;) {
        if(print_flag==true){
            break;
        }
    }



    return 0;
}