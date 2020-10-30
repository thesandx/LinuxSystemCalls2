#include <unistd.h>
#include<stdio.h>
#include <stdlib.h>
#include <fcntl.h>      
#include <sys/socket.h>
#include <sys/stat.h>  
#include <netinet/in.h>

int main(int argc,char const *argv[]){

    struct sockaddr_in server;
    int sock_desc;
    char buff[80];
    

    sock_desc = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port  = htons(43456);


    connect(sock_desc,(void *)(&server),sizeof(server));


    
    write(sock_desc,"Hello server",13);
    read(sock_desc,buff,sizeof(buff));

    printf("Message from server is %s /n :",buff);




    return 0;
}