#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

/*
 * @class Vector3D
 * @brief 3차원 공간 벡터를 표현하는 클래스.
 *
 * CAE 시뮬레이션에서 가장 기본이 되는 데이터 구조 중 하나로, 
 * 위치, 속도, 힘 등 물리량을 나타내는 데 사용된다.
 * 헤더 파일(.h)에는 이처럼 클래스의 선언(어떤 멤버 변수와 멤버 함수가 있는지)을 정의한다.
 */
class Vector3D {
public:
    double x, y, z;

    // --- 생성자 (Constructors) ---

    /*
     * @brief 기본 생성자. Vector3D v1; 처럼 호출된다.
     */
    Vector3D();

    /*
     * @brief x, y, z 값을 직접 지정하는 생성자. Vector3D v2(1.0, 2.0, 3.0); 처럼 호출된다.
     */
    Vector3D(double x_val, double y_val, double z_val);

    /*
     * [심화 학습 #1: 헤더의 '()'는 왜 실행이 아닐까?]
     * Q: 생성자나 함수 뒤에 붙는 소괄호 '()'는 '실행' 문법 아닌가요?
     * A: C++에서 '()'는 문맥에 따라 다릅니다.
     * - 헤더(.h)의 '선언' 시: 함수의 '입력 목록'을 정의하는 설계도의 일부입니다.
     * - 소스(.cpp)의 '호출' 시: 함수를 '지금 당장 실행'하라는 명령어입니다.
     */
     
    /*
     * [심화 학습 #2: 생성자가 두 개인 이유 (함수 오버로딩)]
     * Q: 왜 생성자가 여러 개 필요하고, 어떻게 그게 가능한가요?
     * A (How): '함수 오버로딩(Function Overloading)'이라는 C++ 기능 덕분입니다.
     * 함수 이름이 같아도 '파라미터의 종류나 개수'가 다르면 여러 개를 만들 수 있습니다.
     * 컴파일러가 `Vector3D v1;`인지 `Vector3D v2(1,2,3);`인지를 보고 알맞은 버전을 찾아줍니다.
     * A (Why): 클래스를 쓰는 개발자에게 '편의성'과 '유연성'을 주기 위함입니다.
     * - `Vector3D()`: "일단 기본값(0,0,0)으로 만들어줘" (초기화에 편리)
     * - `Vector3D(x,y,z)`: "내가 원하는 특정 값으로 만들어줘" (정확한 값 설정에 편리)
     * TypeScript에서는 보통 하나의 생성자에 `constructor(x=0, y=0, z=0)`처럼 기본값을 주어 비슷하게 구현합니다.
     */


    // --- 멤버 함수 (Member Functions) ---
    
    /*
     * @brief 벡터의 정보를 콘솔에 출력하는 함수.
     * 함수 뒤의 'const'는 이 함수가 멤버 변수(x, y, z)를 변경하지 않겠다는 약속입니다.
     */
    void print() const;

    /*
     * @brief 다른 Vector3D 객체를 더하는 함수 (값 전달 방식)
     * Vector3D other: 다른 벡터 객체가 통째로 '복사'되어 전달됩니다.
     */
    Vector3D add_by_value(Vector3D other) const;
    
    /*
     * @brief 다른 Vector3D 객체를 더하는 함수 (상수 참조 전달 방식)
     * 모던 C++의 표준적인 '읽기 전용' 데이터 전달 방식입니다.
     */
    Vector3D add_by_reference(const Vector3D& other) const;

    /*
     * [심화 학습 #3: 'const Vector3D& other' 완벽 분석]
     * Q: 'const Vector3D& other'는 정확히 무엇을 의미하나요?
     * A: 세 부분으로 나뉩니다.
     * 1. '&' (참조): 성능. "other는 원본의 복사본이 아닌, '별명'이다. 불필요한 복사를 막아라."
     * 2. 'const': 안전. "그 별명으로 원본을 수정하는 것을 금지한다."
     * 3. 'other': 이름. "함수 내부에서는 이 별명을 'other'라고 부르겠다."
     * 결론: 'other'는 원본 객체를 수정할 수 없는, 빠르고 안전한 '읽기 전용 손잡이'입니다.
     *
     * Q: TypeScript에 비유한다면?
     * A: `other: Readonly<Vector3D>` 와 거의 동일한 아이디어입니다.
     */
};

#endif // VECTOR3D_H