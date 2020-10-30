#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>


int main(int argc,char const *argv[]){

    char* ptr;
    char* ptr1;

    int key = ftok(".",67);
    int shmid = shmget(key,1024,IPC_CREAT|0744);

    ptr  = (char *)shmat(shmid,(void *)0,0); //here instead of 0 u can use RDONLY,WrOnlY etc.

    printf("Write some data \n");
    scanf("%s",ptr);
    shmdt(ptr);

    ptr1  = (char *)shmat(shmid,(void *)0,O_RDONLY);

     printf("Write some data in read only mode \n");
     scanf("%s",ptr1);
     //perror("Error :");
     shmdt(ptr1);

    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}