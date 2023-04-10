cmake_minimum_required(VERSION 2.8)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

include_directories(base gtest)

# BUILD
add_subdirectory(List)
add_subdirectory(List_test)
add_subdirectory(gtest)
