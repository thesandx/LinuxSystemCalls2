#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>


int main(int argc,char const *argv[]){

    if(argc<=1) {
        printf("Did not get any pid to kill\n");
        exit(1);
     } 
     
     int arg1 = atoi(argv[1]);  //argv[0] is the program name
                                //atoi = ascii to int


    kill(arg1,SIGKILL);


    return 0;
}