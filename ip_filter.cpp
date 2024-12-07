#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "lib.h"

// Функция для парсинга IP-адреса с использованием auto и decltype
auto parseIP(const std::string& ip) -> decltype(IPAddress{}) {
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

int main() {
    // Чтение из файла
    std::ifstream file("ip_filter.tsv");
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл ip_filter.tsv" << std::endl;
        return 1;
    }

    std::vector<IPAddress> ipPool;
    std::string line;

    // Чтение файла и парсинг
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string text1, text2, text3;
        std::getline(ss, text1, '\t');
        ipPool.push_back(parseIP(text1));
    }
    file.close();

    // Сортировка с использованием лямбда-функции и кортежей
    std::sort(ipPool.begin(), ipPool.end(), [](const auto& a, const auto& b) {
        return std::make_tuple(a[0], a[1], a[2], a[3]) > std::make_tuple(b[0], b[1], b[2], b[3]);
    });

    // Печать полного списка
    printIPs(ipPool);

    // Функция фильтрации с использованием лямбда-функции
    auto printFiltered = [](const auto& ips, auto predicate) {
        for (const auto& ip : ips) {
            if (predicate(ip)) {
                std::cout << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << "\n";
            }
        }
    };

    // Условие: первый байт == 1
    printFiltered(ipPool, [](const auto& ip) { return ip[0] == 1; });

    // Условие: первый байт == 46, второй == 70
    printFiltered(ipPool, [](const auto& ip) { return ip[0] == 46 && ip[1] == 70; });

    // Условие: любой байт равен 46
    printFiltered(ipPool, [](const auto& ip) {
        return std::any_of(ip.begin(), ip.end(), [](int byte) { return byte == 46; });
    });

    return 0;
}