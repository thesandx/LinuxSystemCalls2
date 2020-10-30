
#include <sys/ipc.h>
#include <sys/msg.h>

#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    struct msqid_ds mq;

    int key = ftok(".",67);
    int msgid = msgget(key,IPC_CREAT|IPC_EXCL|0744);

    msgctl(msgid,IPC_RMID,0);

    return 0;
}


