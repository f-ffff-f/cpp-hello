#include "pointer.h"
#include <iostream>

void pointer() {
    int value = 10; // "value"라는 이름의 사물함에 10을 넣음
    
    // &value는 "value" 사물함의 '주소'를 의미
    // ptr은 '주소'를 저장하는 포인터 변수
    int* ptr = &value; 

    std::cout << "변수 value의 내용물: " << value << std::endl;
    std::cout << "변수 value의 주소: " << &value << std::endl;
    std::cout << "포인터 ptr에 저장된 값 (주소): " << ptr << std::endl;

    // *ptr은 ptr이 가리키는 주소에 있는 '내용물'을 의미
    std::cout << "포인터 ptr이 가리키는 곳의 내용물: " << *ptr << std::endl;
    
    // 포인터를 통해 원본 변수의 값을 변경할 수 있음
    *ptr = 20;
    std::cout << "포인터로 값 변경 후, value의 내용물: " << value << std::endl;

    return;
}