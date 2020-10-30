#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc,char const *argv[]){


    int pipefd[2];

   int i =  pipe(pipefd);

   if(i==-1){
       printf("Error occurred while creating pipe\n");
       exit(0);

   }

   const char msg[] = "This message is for pipe";
   char buff[1024];

   write(pipefd[1],msg,sizeof(msg));
   read(pipefd[0],buff,sizeof(msg));

    printf("Message from pipe is :  %s",buff);




    return 0;
}