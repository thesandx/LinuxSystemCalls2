#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc,char const *argv[]){

	const char pathfile[] = "./mknodfifo";
	//create fifo file
    int fifo =mknod(pathfile, _SC_FIFO | 0666, 0);
    printf("%d",fifo);

	return 0;


}
