#include "HTTPRequest.h"

std::string HTTPRequestHandler::handleRequest(const std::string &request)
{
    // Parse the request and return an appropriate response
    return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello from the HTTP server!</body></html>";
}
