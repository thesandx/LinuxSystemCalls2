#include <unistd.h>
#include<stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>


int main(int argc,char const *argv[]){

    struct rlimit limit;

    limit.rlim_cur=1;
    limit.rlim_max = 184838282;

    int val = setrlimit(RLIMIT_CPU, &limit);


    if(val==0){

        printf("Current limits is %ld\n",limit.rlim_cur);
         printf("Max limits is %ld\n",limit.rlim_max);

    }
    else{
        perror("Error :");
    }



    return 0;
}