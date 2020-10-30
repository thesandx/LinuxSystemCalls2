#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>


int main(int argc,char const *argv[]){

    fd_set rfds;
    struct timeval tv;
    int retval;

    //create the fifo file
    const char pathfile[] = "./fifo22";

    int fifo = mkfifo(pathfile, 0744);

    //open the fifo

    int fd = open("fifo22",O_NONBLOCK|O_RDONLY);


   

           /* Watch stdin (fd 0) to see when it has input. */

        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);

           /* Wait up to 10 seconds. */

           tv.tv_sec = 10;
           tv.tv_usec = 0;

           retval = select(4, &rfds, NULL, NULL, &tv);


           if (retval == -1)
               perror("select()");
           else if (retval){
               printf("Data is available now.\n");
              //read the data
              char buff[1024];
              read(fd,buff,sizeof(buff));
              printf("Data is : %s",buff);
           }

           else
               printf("No data within 10 seconds.\n");

           exit(EXIT_SUCCESS);







    return 0;
}