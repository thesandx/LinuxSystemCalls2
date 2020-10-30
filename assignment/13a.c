#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>


void signal_handler(int signal_no){

   
}

int main(int argc,char const *argv[]){
    printf("%d\n",getpid());
     if(signal(SIGSTOP,signal_handler)==SIG_ERR){
        perror("Error ");
    }
    else{
        raise(SIGINT);

    }

    sleep(30);

   


    return 0;
}