#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include<sys/ipc.h>
#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc,char const *argv[]){

    int key  = ftok(".",67);

    int msgid = msgget(key,IPC_CREAT|IPC_EXCL|0744);



    printf("Key is %d\n",key);
    if(msgid == -1){
        
        //note-if error exists then it means there is existing msg queue
        //to see existing message queues use -> ipcs -q
        //to delete the message queue -> ipcrm -q 0{queue id}
        perror("Error ");
    }
     printf("Message id is %d\n",msgid);



    return 0;
}

