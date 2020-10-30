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


    struct sigaction sa;
    sa.sa_handler = SIG_IGN;

   
    printf("Ctrl+c will not work for 5 sec\n");
    sigaction(SIGINT,&sa,NULL);
    raise(SIGINT);
    sleep(5);
    
    sa.sa_handler = SIG_DFL;
    raise(SIGINT);
    printf("Ctrl+c will  work now");

    sleep(5);

    



    return 0;
}