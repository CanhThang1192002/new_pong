#pragma once

#include <SFML/Network.hpp>
#include <iostream>

class Server {
public:
    Server(unsigned short port);
    ~Server();

    void startListening();
    void acceptConnection();
    void receiveAndSendData();

private:
    sf::TcpListener listener;
    sf::TcpSocket client;
};
