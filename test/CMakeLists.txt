# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)
# Указываем путь к GTest
set(GTEST_DIR "C:/msys64/mingw64/include")

# Находим и добавляем GoogleTest
find_package(GTest REQUIRED)

# Создаем исполнимый файл для тестов
add_executable(test_ip_filter test_ip_filter.cpp)

# Линкуем с GoogleTest и pthread
target_link_libraries(test_ip_filter GTest::GTest GTest::Main pthread)

# Добавляем тест
add_test(NAME test_ip_filter COMMAND test_ip_filter)
