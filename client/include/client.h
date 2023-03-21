#pragma once
#pragma comment(lib, "Ws2_32.lib")


#include<stdio.h>
#include<iostream>
#include<winsock2.h>
#include<stdlib.h>


class Client{
    public:
        Client();
        ~Client();

        SOCKET creatSocket(SOCKADDR_IN & hostAddr, char * hostIP, char * hostPort);
};