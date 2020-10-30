#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc,char const *argv[]){

    int pipe1[2],pipe2[2];

    pipe(pipe1);
    pipe(pipe2);

    int child_pid = fork();

     const char msg1[] = "This message is form parent to child";
    char buff1[1024];

     const char msg2[] = "This message is form child  to parent";
    char buff2[1024];

    if(child_pid>0){
        //close read1 and write2

        close(pipe1[0]); //read1
        close(pipe2[1]); //write2

        //write in pipe1
       write(pipe1[1],msg1,sizeof(msg1));

       //read from pipe2
        read(pipe2[0],buff1,sizeof(msg2));
        printf("Message from child is :  %s",buff1);
    }
    else{

   //close read1 and write2

        close(pipe2[0]); //read2
        close(pipe1[1]); //write1

        //write in pipe2
       write(pipe2[1],msg2,sizeof(msg2));

       //read from pipe1
        read(pipe1[0],buff2,sizeof(msg1));
        printf("Message from parent is :  %s",buff2);
    }


    return 0;
}