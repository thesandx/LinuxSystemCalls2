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
#include <sys/sem.h>


int main(int argc,char const *argv[]){

union semun {
int val; 
struct semid_ds *buf; 
ushort *array;
};


    union semun arg;

    int key = ftok(".",114);

    int semid = semget(key,1,IPC_CREAT|0744);

    arg.val = 2;

    semctl(semid,0,SETVAL,arg);
    
    return 0;
}