#include "reference.h"
#include <iostream>

void reference() {
    int original = 100;
    
    // ref는 original 변수의 또 다른 이름(별명)이 됨
    int& ref = original;

    std::cout << "원본: " << original << std::endl;
    std::cout << "참조: " << ref << std::endl;

    // 별명을 수정하면...
    ref = 200;

    // 원본도 바뀐다!
    std::cout << "참조 수정 후 원본: " << original << std::endl;

    return;
}