#include<stdio.h>
#include <stdlib.h>
#include  <string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int argc,char *argv[]){

    int sock;
    struct sockaddr_in serv_sock;
    char message[30]={0};
    int str_len;

    if (argc!=3){
        printf("Usage :%s <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock==-1)
        error_handling("Socket error\n");

    memset(&serv_sock, 0, sizeof(serv_sock));
    serv_sock.sin_family = AF_INET;
    serv_sock.sin_addr.s_addr = inet_addr(argv[1]);
    serv_sock.sin_port = htons(atoi(argv[2]));

    if(connect(sock,(struct sockaddr*)&serv_sock,sizeof(serv_sock))==-1)
        error_handling("Connect error");

    str_len = read(sock, message, sizeof(message) - 1);
    if(str_len==-1)
        error_handling("read error");
        
    printf("message from server :%s \n", message);
    close(sock);
    return 0;
}