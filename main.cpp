#include "Person.h"
#include <iostream>
#include <memory>

/** 
// Heap 메모리 내에 객체를 생성하고 삭제하는 예제
int main() {
    Person* person = new Person("yu", 30); // 생성자는 메모리 주소를 반환한다
    person->introduce(); // 메모리 주소 참조로 메서드 실행
    delete person; // 메모리 해제
    return 0;
}
*/

/** 
// 함수 스택 내에 객체를 생성하고 삭제하는 예제
int main() {
    // 1. 스택에 Person 객체를 직접 생성합니다.
    // person_stack 변수는 객체 그 자체입니다.
    Person person_stack("yoon", 29);

    // 2. 멤버에 접근할 때는 온점(.)을 사용합니다.
    person_stack.introduce();

    return 0;
} // 3. main 함수가 끝나면 person_stack은 '자동으로' 소멸됩니다.
  //   ~Person() 소멸자가 자동으로 호출됩니다.
*/

// 함수 스택 내에 스마트 포인터를 사용하여 객체를 생성하고 삭제하는 예제
int main() {
    {
        // 이렇게 스마트 포인터를 만듭니다. 'new'를 직접 쓰지 않습니다.
        std::shared_ptr<Person> ptr1 = std::make_shared<Person>("yu",30);
        ptr1->introduce();

        std::cout << "ptr1 사용 횟수: " << ptr1.use_count() << std::endl; // 1
        {
            // ptr2가 같은 객체를 가리키게 함
            std::shared_ptr<Person> ptr2 = ptr1;
            std::cout << "ptr1 사용 횟수: " << ptr1.use_count() << std::endl; // 2
        } // 안쪽 scope가 끝나면서 ptr2는 사라짐 -> 사용 횟수 1로 감소

        std::cout << "ptr1 사용 횟수: " << ptr1.use_count() << std::endl; // 1
    } // 바깥 scope가 끝나면서 ptr1도 사라짐 -> 사용 횟수 0으로 감소
      // 이때 자동으로 Person의 소멸자가 호출되고 메모리가 해제됩니다!

    std::cout << "main 함수 종료" << std::endl;
    return 0;
}