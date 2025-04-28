#include "../core/HttpServer.h"

using namespace std;

HttpServer::HttpServer() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Error creating socket" << endl;
        exit(EXIT_FAILURE);
    }

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    startServer();
};

HttpServer::~HttpServer() {
    close(serverSocket);
}

void HttpServer::bindSocket(int* socket, sockaddr_in* address) {
    if (bind(*socket, (struct sockaddr*)address, sizeof(*address)) == -1) {
        throw runtime_error("Error binding socket");
    }
}

void HttpServer::listenSocket(int* socket) {
    if (listen(*socket, 5) == -1) {
        throw runtime_error("Error listening on socket");
    }
}

void HttpServer::startServer() {
    try {
        bindSocket(&serverSocket, &serverAddress);
        listenSocket(&serverSocket);
        cout << "Server started on port " << PORT << endl;

        while (true) {
            sockaddr_in clientAddress;
            socklen_t clientAddressLength = sizeof(clientAddress);
            int clientSocket = accept(serverSocket, (sockaddr*) &clientAddress, &clientAddressLength);
            
            if (clientSocket == -1) {
                cerr << "Error accepting connection" << endl;
                continue;
            }

            char clientIp[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(clientAddress.sin_addr), clientIp, INET_ADDRSTRLEN);
            
            cout << "Accepted connection from " << clientIp << ":" << ntohs(clientAddress.sin_port) << endl;
            
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, sizeof(buffer));
            read(clientSocket, buffer, sizeof(buffer));

            cout << "Received request: " << buffer << endl;

            string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello World!";
            write(clientSocket, response.c_str(), response.size());

            close(clientSocket);
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}
