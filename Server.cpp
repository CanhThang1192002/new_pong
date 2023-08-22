#include "Server.h"

Server::Server(unsigned short port) {
    if (listener.listen(port) != sf::Socket::Done) {
        std::cout << "Lỗi lắng nghe cổng" << std::endl;
        // Xử lý lỗi nếu cần
    }
}

Server::~Server() {
    // Đóng kết nối và giải phóng tài nguyên
    client.disconnect();
}

void Server::startListening() {
    std::cout << "Đang chờ kết nối từ máy khách..." << std::endl;
    acceptConnection();
    receiveAndSendData();
}

void Server::acceptConnection() {
    if (listener.accept(client) != sf::Socket::Done) {
        std::cout << "Lỗi chấp nhận kết nối" << std::endl;
        // Xử lý lỗi nếu cần
    }
    std::cout << "Kết nối từ máy khách: " << client.getRemoteAddress() << std::endl;
}

void Server::receiveAndSendData() {
    while (true) {
        sf::Packet packet;
        if (client.receive(packet) != sf::Socket::Done) {
            std::cout << "Lỗi nhận dữ liệu" << std::endl;
            // Xử lý lỗi nếu cần
            break;
        }
		float x_mouse, y_mouse, x_ball, y_ball;
        packet >> x_mouse >> y_mouse >> x_ball >> y_ball;

        float mouse_x, mouse_y, ball_x, ball_y;
        sf::Packet responsePacket;
        responsePacket << mouse_x << mouse_y << ball_x << ball_y;
        if (client.send(responsePacket) != sf::Socket::Done) {
            std::cout << "Lỗi gửi kết quả" << std::endl;
            // Xử lý lỗi nếu cần
            break;
        }
    }
    std::cout << "Đóng kết nối." << std::endl;
}
