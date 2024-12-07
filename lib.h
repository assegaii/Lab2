#ifndef LIB_H  // Защита от повторного включения
#define LIB_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include <tuple>
#include <algorithm>

// Определение типа IP-адреса
using IPAddress = std::array<int, 4>;

// Обьявление функции для парсинга IP-адреса
auto parseIP(const std::string& ip) -> IPAddress;
// Обьяввления функции для вывода IP-адресов
auto printIPs(const std::vector<IPAddress>& ips) -> void;


#endif // LIB_H