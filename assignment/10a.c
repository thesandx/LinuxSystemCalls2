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
    printf("Caught the SIGSEGV signal\n");
   
}

int main(int argc,char const *argv[]){

    struct sigaction sa;

    sa.sa_handler = signal_handler;

     if(sigaction(SIGSEGV,&sa,NULL)== -1){
        perror("Error ");
    }

    raise(SIGSEGV);



    return 0;
}