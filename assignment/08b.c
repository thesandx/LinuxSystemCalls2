#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>


void signal_handler(int signal_no){
    printf("Caught the SIGINT signal\n");
   
}

int main(int argc,char const *argv[]){

     if(signal(SIGINT,signal_handler)==SIG_ERR){
        perror("Error ");
    }

    raise(SIGINT);



    return 0;
}