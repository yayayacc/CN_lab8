#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

class Client {
public:
    Client()  = default;
    ~Client() = default;

    SOCKET creatSocket(SOCKADDR_IN& hostAddr, char* hostIP, char* hostPort);
};
