cmake_minimum_required(VERSION 3.20)

project(vb2026_utility_tools)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    cpp_httplib
    URL https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.15.3.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_Declare(
    
)

FetchContent_MakeAvailable(cpp_httplib)

add_executable(vb2026_utility_tools
    src/main.cpp
)
