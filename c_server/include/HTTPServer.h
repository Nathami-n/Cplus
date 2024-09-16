#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <winsock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib") // for linking with the ws2 library

class HTTPServer
{
public:
    HTTPServer(const std::string &ip, int port);
    ~HTTPServer();

    bool intitialize();
    void start();
    void stop();

private:
    SOCKET serverSocket;
    std::string ipAddress;
    int port;

    bool createSocket();
    void handleClient(SOCKET clientSocket);
    void sendResponse(SOCKET clientSocket, const std::string &response);
};

#endif