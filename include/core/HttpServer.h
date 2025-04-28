#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>

#define PORT 8080
#define BUFFER_SIZE 4096

class HttpServer {
    private:
        int serverSocket;
        sockaddr_in serverAddress;
        void bindSocket(int* socket, sockaddr_in* address);
        void listenSocket(int* socket);
    public:
        HttpServer();
        virtual ~HttpServer();
        void startServer();
};

#endif
