#include "Person.h"
#include <iostream>

// 생성자 구현
Person::Person(std::string name, int age) : name_(name), age_(age) {
    std::cout << name_ << " 객체 생성!" << std::endl;
}

// 소멸자 구현
Person::~Person() {
    std::cout << name_ << " 객체 소멸!" << std::endl;
}

// 메서드 구현
void Person::introduce() {
    std::cout << "저는 " << name_ << "이고, " << age_ << "살입니다." << std::endl;
}