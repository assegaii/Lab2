cmake_minimum_required(VERSION 3.10)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 1.0.${PATCH_VERSION})

# Для Debug:
set(CMAKE_CXX_FLAGS_DEBUG "-static-libgcc -static-libstdc++ -std=gnu++14")

# Для Release:
set(CMAKE_CXX_FLAGS_RELEASE "-static-libgcc -static-libstdc++ -std=gnu++14")

# Указываем имя проекта, версию и язык
project(ip_filter VERSION ${PROJECT_VESRION})


set(CMAKE_CXX_STANDARD 14) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем директорию для заголовочных файлов
include_directories(include)

# Добавление подмодуля GoogleTest
add_subdirectory(external/googletest)

# Для Windows
if(WIN32)
    # Настройки для компиляции под Windows
    add_executable(ip_filter ip_filter.cpp lib.cpp)
    add_executable(tests test_ip_filter.cpp lib.cpp)

    # Добавляем нужные библиотеки для Windows
    target_link_libraries(tests gtest gtest_main)

    # Добавляем тесты для Windows
    add_test(NAME ParseIPTest COMMAND tests.exe --gtest_filter=ParseIPTest.ValidIP)
    add_test(NAME SortingTest COMMAND tests.exe --gtest_filter=SortingTest.ReverseLexicographical)
    add_test(NAME FilterTest COMMAND tests.exe --gtest_filter=FilterTest.FirstByteEqualTo1)

    set(CPACK_GENERATOR NSIS)
    set(CPACK_PACKAGE_EXECUTABLES "ip_filter.exe" "ip_filter")
    set(CPACK_PACKAGE_FILE_NAME "ip_filter-${PROJECT_VERSION}-Windows")
    

elseif(UNIX)
    # Для Linux (Ubuntu)
    add_executable(ip_filter ip_filter.cpp lib.cpp)
    add_executable(tests test_ip_filter.cpp lib.cpp)

    # Для Linux добавляем линковку с gtest и gtest_main
    target_link_libraries(tests gtest gtest_main pthread)

    # Добавляем тесты для Linux
    add_test(NAME ParseIPTest COMMAND tests --gtest_filter=ParseIPTest.ValidIP)
    add_test(NAME SortingTest COMMAND tests --gtest_filter=SortingTest.ReverseLexicographical)
    add_test(NAME FilterTest COMMAND tests --gtest_filter=FilterTest.FirstByteEqualTo1)

    set(CPACK_GENERATOR DEB)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dmitryanons@gmail.com)


# Включаем тестирование
include(CTest)
enable_testing()




# Настройки для пакета
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

