#include <iostream>
#include"../include/client.h"

int main() {
#ifdef WINDOWS
    std::cout << "Windows";
#elif LINUX
    std::cout << "Linux";
#endif
    endl(std::cout);
    WSADATA wsadata;
    SOCKET windowsSocket;
    SOCKADDR_IN servADDR;

    if(WSAStartup(MAKEWORD(2, 2), &wsadata) != 0){
        std::cout<<"wsa start up failed!"<<std::endl;
        exit(1);
    }

    Client client;
    char * hostIP = "1.2.3.4"; // TODO:这一部分后面需要更改，可能需要改成NAT穿透
    char * hostPort = "6666";

    windowsSocket = client.creatSocket(servADDR, hostIP, hostPort);
    // 到这一行就已经完成了套接字的创建，接下来就是链接目标主机进行登录的部分了。
}