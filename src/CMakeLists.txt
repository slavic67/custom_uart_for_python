cmake_minimum_required(VERSION 3.8 ) 



PROJECT(customuart)

add_executable(main SerialPort.cpp SerialPort.h uart_for_project.cpp)