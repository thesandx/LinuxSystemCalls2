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

    if(msgid == -1){
        
        //note-if error exists then it means there is existing msg queue
        //to see existing message queues use -> ipcs -q
        //to delete the message queue -> ipcrm -q 0{queue id}
        perror("Error ");
    }

    printf("Enter message type :\n"    );
    char buff[10];
    read(0,buff,sizeof(buff));
    printf("\n");

    msg.mtype = (long)buff;

     printf("Enter message text :\n"    );
    read(0,msg.mtext,sizeof(msg.mtext));
    printf("\n");


    msgsnd(msgid,&msg,strlen(msg.mtext)+1,0);



    return 0;
}