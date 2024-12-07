#include <gtest/gtest.h>
#include "lib.h"

// Тест для функции парсинга IP-адреса
TEST(ParseIPTest, ValidIP) {
    std::string ip = "192.168.0.1";
    IPAddress expected = {192, 168, 0, 1};
    EXPECT_EQ(parseIP(ip), expected);
}

TEST(ParseIPTest, InvalidIP) {
    std::string ip = "256.256.256.256"; // Некорректный IP
    IPAddress expected = {256, 256, 256, 256}; // Стандартное значение
    EXPECT_EQ(parseIP(ip), expected);
}

// Тест для функции сортировки IP-адресов
TEST(SortingTest, ReverseLexicographical) {
    std::vector<IPAddress> input = {
        {1, 10, 1, 1},
        {1, 2, 1, 1},
        {1, 1, 1, 1}
    };
    std::sort(input.rbegin(), input.rend());
    EXPECT_EQ(input[0], (IPAddress{1, 10, 1, 1}));
    EXPECT_EQ(input[1], (IPAddress{1, 2, 1, 1}));
    EXPECT_EQ(input[2], (IPAddress{1, 1, 1, 1}));
}

// Тест для фильтрации IP-адресов по первому байту
TEST(FilterTest, FirstByteEqualTo1) {
    std::vector<IPAddress> input = {
        {1, 10, 1, 1},
        {1, 2, 1, 1},
        {2, 2, 2, 2}
    };
    std::vector<IPAddress> filtered;
    auto printFiltered = [&filtered](const auto& ips, auto predicate) {
        for (const auto& ip : ips) {
            if (predicate(ip)) {
                filtered.push_back(ip);
            }
        }
    };

    printFiltered(input, [](const auto& ip) { return ip[0] == 1; });
    EXPECT_EQ(filtered.size(), 2);
    EXPECT_EQ(filtered[0], (IPAddress{1, 10, 1, 1}));
    EXPECT_EQ(filtered[1], (IPAddress{1, 2, 1, 1}));
}