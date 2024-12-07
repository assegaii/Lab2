cmake_minimum_required(VERSION 3.5.0)

# Указываем имя проекта, версию и язык
project(ip_filter VERSION 0.1.0 LANGUAGES C CXX)

# Указываем стандарт C++ (используем C++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)



# Указываем директорию для заголовочных файлов
include_directories(include)

# Указываем исходные файлы
# В add_executable добавляем все исходные файлы проекта
add_executable(ip_filter ip_filter.cpp)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Включаем тестирование (по вашему запросу)
include(CTest)
enable_testing()

add_subdirectory(test)

# Настройки для пакета (если нужно упаковать проект)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

