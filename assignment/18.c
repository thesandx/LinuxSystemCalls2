#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    int pipefd1[2],pipefd2[2];

    pipe(pipefd1);
    pipe(pipefd2);

    if(!fork()){
         close(1); //close normal stuout
        
        dup2(pipefd1[1],1);  //make your fd as stdout 

        close(pipefd1[0]);  //do not need read part as of now
         close(pipefd2[0]); 
          close(pipefd2[0]); 

        //Note- use whereis ls{cmd name} to find path of command.
        execl("/bin/ls","ls","-l","../",(char *)NULL);
    }

    else{
        if(!fork()){
             close(0);
        dup2(pipefd1[0],0); 

         close(1); 
        
        dup2(pipefd2[1],1);   

        close(pipefd1[0]);  //do not need read part as of now
         close(pipefd1[1]); 
          close(pipefd2[0]); 

        //Note- use whereis ls{cmd name} to find path of command.
        execl("/bin/grep","grep","^d",(char *)NULL);
        }
        else{

            close(0);
            dup2(pipefd2[0],0);

            close(pipefd1[0]);  //do not need read part as of now
         close(pipefd1[1]); 
          close(pipefd2[1]); 

           execl("/usr/bin/wc","wc",(char *)NULL);

        }
    }


    return 0;
}