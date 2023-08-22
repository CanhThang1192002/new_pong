#pragma once

#include <SFML/Network.hpp>
#include <iostream>

class Client {
public:
    Client(const std::string& serverIp, unsigned short port);
    ~Client();

    void connectToServer();
    void sendDataAndReceiveResponse();

private:
    sf::TcpSocket socket;
};
