#include "Person.h"

// // Heap 메모리에 객체를 생성하고 삭제하는 예제
// int main() {
//     Person* person = new Person("yu", 30); // 생성자는 메모리 주소를 반환한다
//     person->introduce(); // 메모리 주소 참조로 메서드 실행
//     delete person; // 메모리 해제
//     return 0;
// }

// 함수 내에서 객체를 생성하고 삭제하는 예제
int main() {
    // 1. 스택에 Person 객체를 직접 생성합니다.
    // person_stack 변수는 객체 그 자체입니다.
    Person person_stack("yoon", 29);

    // 2. 멤버에 접근할 때는 온점(.)을 사용합니다.
    person_stack.introduce();

    return 0;
} // 3. main 함수가 끝나면 person_stack은 '자동으로' 소멸됩니다.
  //   ~Person() 소멸자가 자동으로 호출됩니다.