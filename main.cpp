#include "Person.h"

int main() {
    Person* person = new Person("yu", 30); // 생성자는 메모리 주소를 반환한다
    person->introduce(); // 메모리 주소 참조로 메서드 실행
    delete person; // 메모리 해제
    return 0;
}