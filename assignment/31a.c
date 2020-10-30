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

    int key = ftok(".",112);

    int semid = semget(key,1,IPC_CREAT|0744); //1 means only one semaphore.

    arg.val = 1; //1 means binary,>1 means counting semaphore

    semctl(semid,0,SETVAL,arg);  // 0 means first index of our semaphore array

    //after running this program,in terminal ipcs -a to see your semaphore.

    return 0;
}