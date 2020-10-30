#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc,char const *argv[]){

    int pipefd[2];

    int i = pipe(pipefd);

    if(i==-1){
       printf("Error occurred while creating pipe\n");
       exit(0);

   }

   int child_pid = fork();

   const char msg[] = "This message is form parent to child";
   char buff[1024];

   if(child_pid>0){
       //write from parent
        write(pipefd[1],msg,sizeof(msg));
   }
   else{
       //read from child
       read(pipefd[0],buff,sizeof(msg));
        printf("Message from parent is :  %s",buff);
   }


    return 0;
}