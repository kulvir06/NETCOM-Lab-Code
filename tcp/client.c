#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netdb.h> 
void error(const char *msg) 
{ 
perror(msg); 
exit(0); 
} 
int main(int argc, char *argv[]) 
{ 
int socket1, portnum, n; 
struct sockaddr_in serv_addr; 
struct hostent *server; 
char buffer[256]; 
if (argc < 3) { 
fprintf(stderr,"usage %s hostname port\n", argv[0]); 
exit(0); 
} 
portnum = atoi(argv[2]); 
socket1 = socket(AF_INET, SOCK_STREAM, 0); 
if (socket1 < 0) 
error("ERROR, can't open socket"); 
server = gethostbyname(argv[1]); 
if (server == NULL) { 
fprintf(stderr,"ERROR, there exists no such host\n");

exit(0); 
} 
bzero((char *) &serv_addr, sizeof(serv_addr)); 
serv_addr.sin_family = AF_INET; 
bcopy((char *)server->h_addr, 
(char *)&serv_addr.sin_addr.s_addr, 
server->h_length); 
serv_addr.sin_port = htons(portnum); 
if (connect(socket1,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
error("ERROR,can't connect"); 
printf("Client: "); 
while(1) 
{ 
bzero(buffer,256); 
fgets(buffer,255,stdin); 
n = write(socket1,buffer,strlen(buffer)); 
if (n < 0) 
error("ERROR, writing to socket"); 
bzero(buffer,256); 
n = read(socket1,buffer,255); 
if (n < 0) 
error("ERROR, reading from socket"); 
printf("Server : %s\n",buffer); 
int i = strncmp("Goodbye" , buffer , 7); 
if(i == 0) 
break; 
}
}

