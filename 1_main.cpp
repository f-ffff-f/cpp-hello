// C++ 표준 입출력 라이브러리. std::cout 등을 사용하기 위해 필요합니다.
#include <iostream>

// 우리가 공들여 만든 Vector3D 클래스의 설계도(헤더 파일)를 포함시킵니다.
// 이 코드가 있어야 main 함수에서 Vector3D 클래스를 인식하고 사용할 수 있습니다.
#include "1_Vector3D.h" // 강현님과 함께 최종적으로 검토한 버전의 헤더

/*
 * @brief 프로그램의 시작점 (Entry Point)
 * 모든 C++ 프로그램은 main 함수에서부터 코드를 한 줄씩 실행하기 시작합니다.
 */
int main()
{
    std::cout << "--- Vector3D 클래스 사용 예제 시작 ---" << std::endl;

    // 1. 기본 생성자로 벡터 생성 (0, 0, 0 으로 초기화)
    Vector3D v1;
    std::cout << "v1 (기본 생성): ";
    v1.print(); // v1의 내용을 출력

    // 2. 매개변수가 있는 생성자로 벡터 생성
    Vector3D v2(1.5, 2.5, 3.5);
    std::cout << "v2 (값 지정 생성): ";
    v2.print(); // v2의 내용을 출력

    // 3. add_by_reference 함수를 사용해 두 벡터를 더하기
    // v1.add_by_reference(v2) 가 호출되면,
    // - 'this'는 v1을 가리킵니다.
    // - 'other'는 v2의 별명(참조)이 됩니다.
    // - 함수가 끝나면 두 벡터를 더한 결과가 새로운 Vector3D 객체로 반환됩니다.
    Vector3D result = v1.add_by_reference(v2);

    std::cout << "v1 + v2 결과: ";
    result.print(); // 결과 벡터를 출력

    // C언어 시절부터 내려오는 전통으로, main 함수가 성공적으로 끝났음을
    // 운영체제에 알리기 위해 0을 반환(return)합니다.
    return 0;
}