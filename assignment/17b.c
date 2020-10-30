#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc,char const *argv[]){

    int pipefd[2];

    pipe(pipefd);

    int i = fork();

    if(i==0){
        close(1); //close normal stuout
        
        dup2(pipefd[1],1);  //make your fd as stdout 

        close(pipefd[0]);  //do not need read part as of now

        //Note- use whereis ls{cmd name} to find path of command.
        execl("/bin/ls","ls","-l",(char *)NULL);
        

    }
    else{

         close(0);
         dup2(pipefd[0],0);
         close(pipefd[1]);
        //Note- use whereis ls{cmd name} to find path of command.
        execl("/usr/bin/wc","wc",(char *)NULL);
        //close(pipefd[0]);





    }


    return 0;
}        
