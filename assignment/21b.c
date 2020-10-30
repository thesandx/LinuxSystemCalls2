#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

char buff[1024];
//open fifo1 in write and fifo2 in read

int fd1 = open("fifo21a",O_RDONLY);
int fd2 = open("fifo21b",O_WRONLY);

read(fd1,buff,sizeof(buff));
printf("message from fifo is %s",buff);

char msg[]  = "Saying Hi from 21b to 21a";

write(fd2,msg,sizeof(msg));




close(fd2);
return 0;
}