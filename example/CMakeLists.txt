cmake_minimum_required(VERSION 3.8)

project(RemoteSerialPortExamples)

set(CMAKE_CXX_STANDARD 17)

file(GLOB RemoteSerialPortExamples_src CONFIGURE_DEPENDS "*.hpp" "*.cpp")

add_executable(RemoteSerialPortExamples ${RemoteSerialPortExamples_src})
target_link_libraries(RemoteSerialPortExamples)


