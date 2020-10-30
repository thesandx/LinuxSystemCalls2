#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>

int main(int argc,char const *argv[]){

    struct msgbuf {
         long mtype;
         char mtext[1024];
    }msg;

    int key = ftok(".",67);
    int msgid = msgget(key,IPC_CREAT|IPC_EXCL|0744);

    msg.mtype = 30;

    msgrcv(msgid,&msg,sizeof(msg.mtext),msg.mtype,0);

    printf("Message is %s\n",msg.mtext);





    return 0;
}