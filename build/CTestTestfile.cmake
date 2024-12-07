# CMake generated Testfile for 
# Source directory: D:/Study/C++/Labs/Lab2
# Build directory: D:/Study/C++/Labs/Lab2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ParseIPTest "tests.exe" "--gtest_filter=ParseIPTest.ValidIP")
set_tests_properties(ParseIPTest PROPERTIES  _BACKTRACE_TRIPLES "D:/Study/C++/Labs/Lab2/CMakeLists.txt;34;add_test;D:/Study/C++/Labs/Lab2/CMakeLists.txt;0;")
add_test(SortingTest "tests.exe" "--gtest_filter=SortingTest.ReverseLexicographical")
set_tests_properties(SortingTest PROPERTIES  _BACKTRACE_TRIPLES "D:/Study/C++/Labs/Lab2/CMakeLists.txt;35;add_test;D:/Study/C++/Labs/Lab2/CMakeLists.txt;0;")
add_test(FilterTest "tests.exe" "--gtest_filter=FilterTest.FirstByteEqualTo1")
set_tests_properties(FilterTest PROPERTIES  _BACKTRACE_TRIPLES "D:/Study/C++/Labs/Lab2/CMakeLists.txt;36;add_test;D:/Study/C++/Labs/Lab2/CMakeLists.txt;0;")
subdirs("external/googletest")
