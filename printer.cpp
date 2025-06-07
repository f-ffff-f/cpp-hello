// printer.cpp
#include "printer.h" // 우리가 만든 헤더 파일을 포함
#include <iostream>    // std::cout을 사용하기 위해 포함

// printer.h에 선언했던 함수의 실제 동작을 "구현"합니다.
void print_message() {
    std::cout << "Hello from a separate file!" << std::endl;
}