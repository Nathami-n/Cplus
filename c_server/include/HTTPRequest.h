#ifndef HTTPREQUESTHANDLER_H
#define HTTPREQUESTHANDLER_H

#include <string>

class HTTPRequestHandler {
public:
    std::string handleRequest(const std::string& request);
};

#endif
