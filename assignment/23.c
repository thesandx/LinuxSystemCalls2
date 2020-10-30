#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){



    printf("Maximum number of file can be opened within a process is %ld \n",sysconf(_SC_OPEN_MAX));

    const char pathfile[] = "./fifo23";

    int fifo = mkfifo(pathfile, 0744);


    printf("Size of pipe is %ld \n",pathconf("fifo23",_PC_PIPE_BUF));
    return 0;
}