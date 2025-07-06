#include <iostream>
#include <vector>
// Vector3D 클래스는 편의상 생략합니다. float 타입을 직접 사용하겠습니다.

void print_status(const std::vector<float> &vec)
{
    std::cout << "요소 개수(size): " << vec.size()
              << ", 할당된 공간(capacity): " << vec.capacity() << std::endl;
}

int main()
{
    // === 1. size와 capacity의 관계 ===
    std::cout << "--- 요소를 하나씩 추가하며 size와 capacity 변화 관찰 ---" << std::endl;
    std::vector<float> numbers;
    print_status(numbers);

    for (int i = 0; i < 10; ++i)
    {
        numbers.push_back(i * 1.1f);
        std::cout << (i + 1) << "번째 요소 추가 후 -> ";
        print_status(numbers); // capacity가 어떻게 2의 거듭제곱으로 증가하는지 관찰해보세요.
    }

    // === 2. reserve를 이용한 사전 할당 최적화 ===
    std::cout << "\n--- reserve()로 공간을 미리 할당 ---" << std::endl;
    std::vector<float> numbers_reserved;
    numbers_reserved.reserve(10); // 미리 10개 분량의 공간을 확보합니다.

    std::cout << "reserve(10) 호출 후 -> ";
    print_status(numbers_reserved);

    for (int i = 0; i < 10; ++i)
    {
        numbers_reserved.push_back(i * 1.1f);
        std::cout << (i + 1) << "번째 요소 추가 후 -> ";
        print_status(numbers_reserved); // capacity가 변하지 않는 것을 확인하세요! (재할당 없음)
    }

    // === 3. 이터레이터를 이용한 순회 ===
    std::cout << "\n--- 이터레이터를 사용한 전통적인 방식의 순회 ---" << std::endl;
    // std::vector<float>::iterator는 이터레이터의 정식 타입 이름입니다. auto로 간단히 표현 가능합니다.
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        // it은 포인터처럼 행동하므로, 가리키는 값에 접근하려면 역참조 연산자(*)를 사용합니다.
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}