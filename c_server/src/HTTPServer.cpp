#include "HTTPServer.h"
#include <iostream>

namespace HTTP
{
    HTTPServer::HTTPServer(const std::string &ip, int port)
        : ipAddress(ip), port(port), serverSocket(INVALID_SOCKET) {}

    HTTPServer::~HTTPServer()
    {
        stop();
    }

    bool HTTPServer::initialize()
    {
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (result != 0)
        {
            std::cerr << "WSAStartup failed" << result << std::endl;
            return false;
        }

        return createSocket();
    }

    bool HTTPServer::createSocket()
    {
        serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (serverSocket == INVALID_SOCKET)
        {
            std::cerr << "Couldn't create socket" << WSAGetLastError() << std::endl;
            WSACleanup();
            return false;
        }

        sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        serverAddr.sin_addr.s_addr = inet_addr(ipAddress.c_str());

        if (bind(serverSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        {
            std::cerr << "Bind failed" << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            return false;
        }

        if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
        {
            std::cerr << "Listen failed" << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            return false;
        }

        std::cout << "Server listening on port" << ipAddress << ":" << port << std::endl;
        return true;
    }

    void HTTPServer::start()
    {
        sockaddr_in clientAddr;
        int clientAddrSize = sizeof(clientAddr);

        while (true)
        {
            SOCKET clientSocket = accept(serverSocket, (sockaddr *)&clientAddr, &clientAddrSize);
            if (clientSocket == INVALID_SOCKET)
            {
                std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;
                continue;
            }

            handleClient(clientSocket);
            closesocket(clientSocket);
        }
    }

    void HTTPServer::handleClient(SOCKET clientSocket)
    {
        char buffer[1024];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived > 0)
        {
            std::cout << "Received request: " << std::string(buffer, bytesReceived) << std::endl;
            sendResponse(clientSocket, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!");
        }
    }

    void HTTPServer::sendResponse(SOCKET clientSocket, const std::string &response)
    {
        send(clientSocket, response.c_str(), response.size(), 0);
    }

    void HTTPServer::stop()
    {
        closesocket(serverSocket);
        WSACleanup();
    }

}
