cmake_minimum_required(VERSION 3.19)
project(leetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(leetcode main.cpp primaryAlgorithms/array.cpp)

target_include_directories(leetcode PRIVATE
        common.h
        primaryAlgorithms/array.h
)

# vcpkg
find_package(Boost REQUIRED COMPONENTS
        unit_test_framework
)
target_include_directories(leetcode PUBLIC
        ${Boost_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}
)
target_link_libraries(leetcode ${Boost_LIBRARIES})