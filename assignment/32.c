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


struct sembuf {
ushort sem_num;
short sem_op; 
short sem_flg; 
};


    union semun arg;

    int key = ftok(".",112);

    int semid = semget(key,1,IPC_CREAT|0744); //1 means only one semaphore.

    arg.val = 1; //1 means binary,>1 means counting semaphore

    semctl(semid,0,SETVAL,arg);  // 0 means first index of our semaphore array

    struct sembuf sops = {0,-1,0}; //first semaphore,decrease the value,new value is 0;

    semop(semid,&sops,1); //locked

    //inside critical section


    sops.sem_op = 1; //increase the semaphore before releasing lock;
    semop(semid,&sops,1); //lock released.

    semctl(semid,0,IPC_RMID,arg); //delete the semaphore




    return 0;
}