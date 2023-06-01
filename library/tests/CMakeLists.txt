cmake_minimum_required(VERSION 3.8)

project(RemoteSerialPortTests)

set(CMAKE_CXX_STANDARD 14)

file(GLOB RemoteSerialPortTests_src CONFIGURE_DEPENDS "*.hpp" "*.cpp")

add_executable(RemoteSerialPortTests ${RemoteSerialPortTests_src})
target_link_libraries(RemoteSerialPortTests)

