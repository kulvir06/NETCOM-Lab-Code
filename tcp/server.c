#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
void error(const char *msg) 
{ 
perror(msg); 
exit(1); 
} 
int main(int argc, char *argv[]) 
{ 
    int socket1, newsocket1, portNum;
    socklen_t clilen;
    char buffer[255];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    if (argc < 2) {
    fprintf(stderr,"ERROR, port not given\n");
    exit(1);
    }
    socket1 = socket(AF_INET, SOCK_STREAM, 0);
    if (socket1 < 0)
    error("ERROR can't open socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portNum = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portNum);
    if (bind(socket1, (struct sockaddr *) &serv_addr,
    sizeof(serv_addr)) < 0)
    error("ERROR can't bind");
    listen(socket1,5);
    clilen = sizeof(cli_addr);
    newsocket1 = accept(socket1,
    (struct sockaddr *) &cli_addr,
    &clilen);
    if (newsocket1 < 0)
    error("ERROR can't accept");
    while(1)
    {
    bzero(buffer,255);
    n = read(newsocket1,buffer,255);
    if (n < 0) error("ERROR ,can't read");
    printf("Client: %s\n",buffer);
    bzero(buffer,255);
    fgets(buffer,255,stdin);
    n = write(newsocket1,buffer,strlen(buffer));
    if (n < 0) error("ERROR ,can't write");
    int i=strncmp("Goodbye" , buffer, 7);
    if(i == 0)
    break;
    }
    close(newsocket1);
    close(socket1);
    return 0;
}
