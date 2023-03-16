#include<iostream>

#include<WINSOCK2.H>

#include<STDIO.H>

#include<cstring>

#include <Ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
   WSADATA wsadata;
   int nRes = WSAStartup(MAKEWORD(2, 2), &wsadata);

   SOCKET sock = socket(PF_INET, SOCK_STREAM, 0);
   
   struct sockaddr_in sockAddr;
   
   sockAddr.sin_family = PF_INET; 
   sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //只需要在这里指向服务器 ip 就可以了 
   sockAddr.sin_port = htons(1234);

   //连接服务器
   connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

   while (1) {
       char recvBuf[50];
       char sendBuf[50]={"Hello server"};

       printf("跟服务端说: ");
       scanf("%s",sendBuf);

       send(sock, sendBuf, strlen(sendBuf) + 1, 0);

       recv(sock, recvBuf, 50, 0);
       printf("服务端跟你说: ");
       printf("%s\n", recvBuf);
   }

   closesocket(sock);

   WSACleanup();
   system("pause");
}