//
//  multi-client.cpp
//  first_c++_on_mac
//
//  Created by hkz on 2017/5/19.
//  Copyright © 2017年 hkz. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#define BUFFER_SIZE 1024
//      现在的逻辑是。  我可以往服务器发消息。然后服务器会收到。  如果我加上。  @谁谁谁。   然后就可以指定给谁发消息。听起来不错。   主要是服务器那里的代码。 因为我每次都是
int main(int argc, const char * argv[])
{
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8000);
    if(inet_pton(AF_INET,argv[1],&server_addr.sin_addr)<=0)
    {
      //  printf("inet_pton error\n");
        exit(0);
    }
    //   server_addr.sin_addr.s_addr = htonl("42.159.124.123");
    bzero(&(server_addr.sin_zero), 8);
    
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock_fd == -1)
    {
        perror("socket error");
        return 1;
    }
    char recv_msg[BUFFER_SIZE];
    char input_msg[BUFFER_SIZE];
    printf("i'm still alive!!!");
    if(connect(server_sock_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == 0)
    {
        //printf("i'm still alive!!!");
        fd_set client_fd_set;
        struct timeval tv;
        
        while(1)
        {
            tv.tv_sec = 20;
            tv.tv_usec = 0;
            FD_ZERO(&client_fd_set);
            FD_SET(STDIN_FILENO, &client_fd_set);
            FD_SET(server_sock_fd, &client_fd_set);
            
            select(server_sock_fd + 1, &client_fd_set, NULL, NULL, &tv);
            if(FD_ISSET(STDIN_FILENO, &client_fd_set))
            {
                bzero(input_msg, BUFFER_SIZE);
                fgets(input_msg, BUFFER_SIZE, stdin);
                if(send(server_sock_fd, input_msg, BUFFER_SIZE, 0) == -1)
                {
                    perror("发送消息出错!\n");
                }
            }
            if(FD_ISSET(server_sock_fd, &client_fd_set))
            {
                bzero(recv_msg, BUFFER_SIZE);
                long byte_num = recv(server_sock_fd, recv_msg, BUFFER_SIZE, 0);
                if(byte_num > 0)
                {
                    if(byte_num > BUFFER_SIZE)
                    {
                        byte_num = BUFFER_SIZE;
                    }
                    recv_msg[byte_num] = '\0';
                    printf("服务器:%s\n", recv_msg);
                }
                else if(byte_num < 0)
                {
                    printf("接受消息出错!\n");
                }
                else
                {
                    printf("服务器端退出!\n");
                    exit(0);
                }
            }
        }
        //}
    }
    printf("i'm still alive!!!");
    return 0;
}

