#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

void *threadFunc(void *data) {
    pthread_t thread_id = pthread_self(); 
    printf("Thread id is %ld \n",(long)thread_id);  
}

int main(int argc,char const *argv[]){
    pthread_t tid;

    pthread_create(&tid,NULL,threadFunc,NULL);

    pthread_exit(NULL);

    //note to compile it use gcc -pthread 06.c


    return 0;
}