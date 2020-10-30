#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

char buff[1024];
//open this file

int fd = open("fifo20",O_RDONLY);

read(fd,buff,sizeof(buff));
printf("message from fifo is %s",buff);
close(fd);
return 0;
}