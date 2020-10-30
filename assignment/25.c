
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

    if(msgid == -1){
        
        //note-if error exists then it means there is existing msg queue
        //to see existing message queues use -> ipcs -q
        //to delete the message queue -> ipcrm -q 0{queue id}
        perror("Error ");
    }

    msgctl(msgid,IPC_STAT,&mq);

    printf("access permission:            %ld\n", (long) mq.msg_perm.mode);
    printf("uid:            %ld\n", (long) mq.msg_perm.uid);
    printf("gid:            %ld\n", (long) mq.msg_perm.gid);
    printf("time of last message sent:            %ld\n", (long) mq.msg_stime);
    printf("time of last message recieved:            %ld\n", (long) mq.msg_rtime);
    printf("time of last change in the message queue:            %ld\n", (long) mq.msg_ctime);
    printf("size of the queue:            %ld\n", (long) mq.__msg_cbytes);
    printf("number of messages in the queue:            %ld\n", (long) mq.msg_qnum);
    printf("maximum number of bytes allowed:            %ld\n", (long) mq.msg_qbytes);
    printf("pid of the msgsnd:            %ld\n", (long) mq.msg_lspid);
    printf("pid of the msgrcv:            %ld\n", (long) mq.msg_lrpid);






    


    return 0;
}
