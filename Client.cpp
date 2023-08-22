#include "Client.h"

Client::Client(const std::string& serverIp, unsigned short port) {
    if (socket.connect(serverIp, port) != sf::Socket::Done) {
        std::cout << "Lỗi kết nối đến máy chủ" << std::endl;
        // Xử lý lỗi nếu cần
    }
}

Client::~Client() {
    socket.disconnect();
}

void Client::connectToServer() {
    sendDataAndReceiveResponse();
}

void Client::sendDataAndReceiveResponse() {
    while (true) {
        float mouse_x, mouse_y, ball_x, ball_y;

        sf::Packet packet;
        packet << mouse_x << mouse_y << ball_x << ball_y;

        if (socket.send(packet) != sf::Socket::Done) {
            std::cout << "Lỗi gửi dữ liệu" << std::endl;
            // Xử lý lỗi nếu cần
            break;
        }

        sf::Packet responsePacket;
        if (socket.receive(responsePacket) != sf::Socket::Done) {
            std::cout << "Lỗi nhận kết quả" << std::endl;
            // Xử lý lỗi nếu cần
            break;
        }

        float x_mouse, y_mouse, x_ball, y_ball;
        responsePacket >> x_mouse >> y_mouse >> x_ball >> y_ball;
        //std::cout << "Kết quả từ máy chủ: " << result << std::endl;
    }
    std::cout << "Đóng kết nối." << std::endl;
}
