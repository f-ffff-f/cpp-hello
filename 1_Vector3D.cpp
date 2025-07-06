// 1. 헤더 파일 포함
// 우리가 정의한 Vector3D 클래스의 '설계도'를 가져온다.
// 이 코드가 있어야 컴파일러가 Vector3D 클래스의 존재와 멤버들을 알 수 있다.
#include "1_Vector3D.h"

// 2. 생성자 구현

// [문법] Vector3D::Vector3D()
// '::' (Scope Resolution Operator)는 "어떤 클래스에 소속된 함수인지"를 명확히 하는 연산자이다.
// "이 함수는 Vector3D 클래스에 소속된, 파라미터가 없는 생성자입니다" 라는 의미.
//
// [문법] : x(0.0), y(0.0), z(0.0)
// '멤버 초기화 리스트(Member Initializer List)'라고 부른다.
// 생성자 본문 '{ }'에서 값을 할당하는 것보다 더 효율적이고 표준적인 초기화 방식이다.
// x 멤버는 0.0으로, y 멤버는 0.0으로, z 멤버는 0.0으로 '생성과 동시에 초기화'한다.
Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0)
{
    // 보통 초기화 리스트에서 모든 작업을 끝내므로, 본문은 비어있는 경우가 많다.
}

// 위와 마찬가지로, Vector3D 클래스에 소속된, double 타입 3개를 받는 생성자이다.
// 멤버 x는 파라미터 x_val 값으로, y는 y_val 값으로, z는 z_val 값으로 초기화한다.
Vector3D::Vector3D(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val)
{
    // 여기도 본문은 비어있다.
}

// 3. 멤버 함수 구현

// Vector3D 클래스에 소속된 print 함수.
// 헤더 파일에 선언된 것과 마찬가지로, 구현부에도 const를 반드시 붙여주어야 한다.
void Vector3D::print() const
{
    // std::cout은 C++의 표준 콘솔 출력 스트림이다.
    // << 연산자를 이용해 출력할 내용들을 이어붙인다.
    // std::endl은 줄바꿈(newline)을 의미한다.
    std::cout << "Vector3D(" << x << ", " << y << ", " << z << ")" << std::endl;
}

// Vector3D 클래스에 소속된 add_by_value 함수.
// 이 함수는 Vector3D 타입의 객체를 반환(return)한다.
Vector3D Vector3D::add_by_value(Vector3D other) const
{
    // [문법] this->x
    // 'this'는 멤버 함수 안에서 '함수를 호출한 객체 자신'을 가리키는 포인터이다.
    // 만약 `v1.add_by_value(v2)` 로 호출했다면, 'this'는 v1을 가리킨다.
    // this->x는 v1의 x, this->y는 v1의 y를 의미한다.
    // other.x는 파라미터로 '복사'되어 들어온 v2의 x를 의미한다.
    double res_x = this->x + other.x;
    double res_y = this->y + other.y;
    double res_z = z + other.z; // 'this->'는 생략 가능하며, 컴파일러가 자동으로 인식한다.

    // 계산된 결과로 새로운 Vector3D 객체를 생성하여 반환한다.
    return Vector3D(res_x, res_y, res_z);
}

/*
 * [심화 학습: 함수 시그니처(Signature) 완전 해부]
 * Q: 'Vector3D Vector3D::add_by_reference(const Vector3D& other) const' 이 한 줄을 원자 단위까지 설명해주세요.
 * A: 이 한 줄은 함수의 모든 것을 정의하는, 매우 정밀한 '설계 명세서'입니다. 각 부분의 의미는 다음과 같습니다.
 *
 * [1]        [2]    [3]         [4]             ( [6]    [7]     [8]   [9]  )   [10]
 * Vector3D   Vector3D::  add_by_reference        ( const Vector3D& other ) const
 *
 * [1] Vector3D: '반환 타입'. 이 함수가 모든 작업을 마친 후 최종적으로 반환할 결과물의 종류입니다.
 * [2] Vector3D: '클래스 소속'. 이 함수가 Vector3D 클래스에 소속된 멤버 함수임을 나타냅니다.
 * [3] ::      : '스코프 지정 연산자'. 2번과 4번을 연결하는 접착제 역할입니다. ('~의' 라고 해석)
 * [4] add_by_reference: '함수 이름'. 함수의 고유한 이름입니다.
 * [5] ( ... ) : '파라미터 목록'. 함수가 외부로부터 받을 재료들을 정의하는 '투입구'입니다.
 * [6] const   : '파라미터 수식어 (읽기 전용)'. 투입구로 들어온 재료(other)를 절대 수정하지 않겠다는 약속입니다. (안전성)
 * [7] Vector3D: '파라미터 타입'. 투입될 재료의 종류는 반드시 Vector3D여야 합니다.
 * [8] &       : '참조 지정자'. 재료를 복사하지 않고 원본의 '별명'을 사용하겠다는 의미입니다. (성능)
 * [9] other   : '파라미터 이름'. 함수 안에서는 투입된 재료를 'other'라는 이름표로 부릅니다.
 * [10] const  : '멤버 함수 수식어'. 이 함수는 자기 자신의 멤버 변수(this->x 등)를 절대 변경하지 않는 '읽기 전용 함수'임을 서약합니다.
 *
 * [최종 해석]
 * "Vector3D 클래스 소속의 add_by_reference 함수는, 수정 불가능한 Vector3D의 참조인 other를 입력받아,
 * 최종 결과물로 Vector3D 객체를 반환하며, 이 함수 자체는 자기 데이터를 절대 수정하지 않습니다."
 */

// Vector3D 클래스에 소속된 add_by_reference 함수.
Vector3D Vector3D::add_by_reference(const Vector3D &other) const
{
    // *** 매우 중요한 포인트 ***
    // 함수 내부의 '사용법'은 add_by_value와 완전히 동일하다.
    // C++은 '어떻게 전달되었는지(값 vs 참조)'와 상관없이, 함수 안에서는 동일한 문법으로 파라미터를 사용한다.
    // 차이점은 눈에 보이지 않는 곳에 있다: 이 함수는 호출될 때 'other'를 위한 메모리 복사가 발생하지 않았다.
    double res_x = this->x + other.x;
    double res_y = this->y + other.y;
    double res_z = this->z + other.z;

    return Vector3D(res_x, res_y, res_z);
}