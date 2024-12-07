#include "lib.h"

// Функция для парсинга IP-адреса
auto parseIP(const std::string& ip) -> IPAddress {
    IPAddress address{};
    std::stringstream ss(ip);
    for (int i = 0; i < 4; ++i) {
        std::string byte;
        std::getline(ss, byte, '.');
        address[i] = std::stoi(byte);
    }
    return address;
}

// Универсальная функция для вывода списка IP-адресов
auto printIPs(const std::vector<IPAddress>& ips) -> void {
    for (const auto& ip : ips) {
        std::cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << "\n";
    }
}