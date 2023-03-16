#include <iostream>

#include <stdio.h> 

#include <winsock2.h> 

#include <Ws2tcpip.h>

#pragma comment(lib,"ws2_32.lib") 

int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    SOCKET serverSock = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sockAddr;

    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = htons(INADDR_ANY);
    sockAddr.sin_port = htons(1234);
    bind(serverSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

    listen(serverSock, 20);

    SOCKADDR cIntAddr; 
    int nSize = sizeof(SOCKADDR);
    SOCKET cIntSock = accept(serverSock, (SOCKADDR*)&cIntAddr, &nSize);

    while (1) {
    
        char sendBuf[50]={"Hello client"};
        char recvBuf[50];

        recv(cIntSock, recvBuf, 50, 0);
        printf("来自客户端:");
        printf("%s\n", recvBuf);

        printf_s("请输入内容:");
        scanf("%s",sendBuf);
        send(cIntSock, sendBuf, strlen(sendBuf) + 1, 0);
    }
	//关闭
    closesocket(cIntSock);
    closesocket(serverSock);
    WSACleanup();
    return 0;
}