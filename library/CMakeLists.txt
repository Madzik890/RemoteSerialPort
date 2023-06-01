cmake_minimum_required(VERSION 3.8)

project(RemoteSerialPort)

set(CMAKE_CXX_STANDARD 17)

file(GLOB RemoteSerialPort_src CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp" "src/*/*.hpp" "src/*/*.cpp" "src/*/*/*.hpp" "src/*/*/*.cpp" "src/*/*/*/*.hpp" "src/*/*/*/*.cpp" )

include_directories(${PROJECT_SOURCE_DIR}/src)

add_library(RemoteSerialPort STATIC ${RemoteSerialPort_src})
target_link_libraries(RemoteSerialPort)
