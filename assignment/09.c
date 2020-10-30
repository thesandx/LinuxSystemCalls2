#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
#include<sys/time.h>

int main(int argc,char const *argv[]){

//     ● Ctrl + C - SIGINT
// ● Ctrl + \ - SIGQUIT
// ● Ctrl + Z - SIGTSTP

   
    printf("Ctrl+c will not work for 5 sec\n");
    signal(SIGINT,SIG_IGN);
    sleep(5);
    
    printf("Ctrl+c will  work now\n");
    signal(SIGINT,SIG_DFL);
    sleep(5);

    



    return 0;
}