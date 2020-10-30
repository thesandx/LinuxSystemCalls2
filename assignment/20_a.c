#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){


const char pathfile[] = "./fifo20";
	//create fifo file
int fifo = mkfifo(pathfile, 0744);

//open this file

int fd = open("fifo20",O_WRONLY);
char msg[]  = "message written for fifo";

write(fd,msg,sizeof(msg));
close(fd);
return 0;
}