#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    int fd = open("fifo22",O_WRONLY);

    char msg[] = "Hey 22a,How u Doin";

    write(fd,msg,sizeof(msg));

    return 0;
}