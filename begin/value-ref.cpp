#include <string>
#include <iostream>

// 1. 값에 의한 전달 (비효율적인 복사 발생)
void function_by_value(std::string str) {
    str += " (modified)"; // 복사본이 수정됨. 원본은 그대로.
}

// 2. 참조에 의한 전달 (효율적. 원본 수정 가능)
void function_by_reference(std::string& str) {
    str += " (modified)"; // 원본이 직접 수정됨.
}

void value_ref() {
    std::string my_string = "Hello";
    function_by_value(my_string);
    std::cout << "값 전달 후: " << my_string << std::endl; // 출력: Hello

    my_string = "Hello";
    function_by_reference(my_string);
    std::cout << "참조 전달 후: " << my_string << std::endl; // 출력: Hello (modified)
    
    return;
}