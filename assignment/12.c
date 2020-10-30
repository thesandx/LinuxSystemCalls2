#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>


int main(int argc,char const *argv[]){

    if(!fork()){
        printf("Current parent id is %d \n",getppid());
        printf("Killing the parent now,wait for 5 sec\n");
        kill(getppid(),SIGKILL);
        sleep(5);
        printf("new parent id is %d \n",getppid());

        
    }
    else{
        printf("Parent is going to sleep now\n");
        sleep(1000);
    }


    return 0;
}