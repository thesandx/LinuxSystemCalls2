#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char const *argv[]){

    //long val = sysconf(_SC_ARG_MAX);

    printf("maximum length of the arguments to the exec family of functions: %ld\n",sysconf(_SC_ARG_MAX));
    printf("maximum number of simultaneous process per user id: %ld\n",sysconf(_SC_CHILD_MAX));
    printf("number of clock ticks (jiffy) per second: %ld\n",sysconf(_SC_CLK_TCK));
    printf("maximum number of open files: %ld\n",sysconf(_SC_OPEN_MAX));
    printf("size of a page: %ld\n",sysconf(_SC_PAGE_SIZE));
    printf("total number of pages in the physical memory: %ld\n",sysconf(_SC_PHYS_PAGES));
    printf("number of currently available pages in the physical memory.: %ld\n",sysconf(_SC_AVPHYS_PAGES));



    return 0;
}