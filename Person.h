#pragma once
#include <string>

class Person {
public: // 이 아래 멤버들은 외부에서 접근 가능
    // 생성자 (Constructor): 객체가 생성될 때 호출됨
    Person(std::string name, int age);

    // 소멸자 (Destructor): 객체가 소멸될 때 호출됨
    ~Person();

    void introduce();

private: // 이 아래 멤버들은 클래스 내부에서만 접근 가능
    std::string name_;
    int age_;
};