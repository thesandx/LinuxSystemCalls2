#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){
char buff[1024];

const char pathfile1[] = "./fifo21a";
const char pathfile2[] = "./fifo21b";
	//create fifo file
int fifo1 = mkfifo(pathfile1, 0744);
int fifo2 = mkfifo(pathfile2, 0744);

//open fifo1 in write and fifo2 in read

int fd1 = open("fifo21a",O_WRONLY);
int fd2 = open("fifo21b",O_RDONLY);

char msg[]  = "Saying Hi from 21a to 21b";

write(fd1,msg,sizeof(msg));

read(fd2,buff,sizeof(buff));
printf("message from fifo is %s",buff);

close(fd1);
return 0;
}