#include<iostream>

#include<WINSOCK2.H>

#include<STDIO.H>

#include<cstring>

#include <Ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    // 创建windows下的网络通信数据结构
    WSADATA wsadata;
    WORD protocol_family = MAKEWORD(2, 2);
    int nRes = WSAStartup(protocol_family, &wsadata);

    // 创建客户端使用的套接字
    SOCKET client_sock = socket(PF_INET, SOCK_STREAM, 0);

    // 指定用户端所用的套接字信息
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockaddr_in));
   sockAddr.sin_family = PF_INET; // 指定为TCP
   sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //只需要在这里指向服务器 ip 就可以了 
   sockAddr.sin_port = htons(1234); // 指向服务器端口，此行以及上面那一行注意和server的保持一致

    //连接服务器
    connect(client_sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

    while (1) {
        char recvBuf[50];
        char sendBuf[50]={"Hello server"};

        printf("跟服务端说: ");
        scanf("%s",sendBuf);

        send(client_sock, sendBuf, strlen(sendBuf) + 1, 0);

        recv(client_sock, recvBuf, 50, 0);
        printf("服务端跟你说: ");
        printf("%s\n", recvBuf);
    }

    closesocket(client_sock);

    WSACleanup();
    system("pause");
}