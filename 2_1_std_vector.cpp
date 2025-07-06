#include <iostream>
#include <vector> // std::vector를 사용하기 위해 반드시 포함해야 하는 헤더

// 1주차에서 만들었던 Vector3D 클래스 (간략화 버전)
// 실제 프로젝트에서는 Vector3D.h 파일로 분리하고 #include "Vector3D.h" 로 포함합니다.
class Vector3D
{
public:
    float x, y, z;

    // 기본 생성자
    Vector3D() : x(0), y(0), z(0) {}

    // 매개변수가 있는 생성자
    Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

    // Vector3D 객체의 정보를 출력하는 const 멤버 함수
    void print() const
    {
        std::cout << "Vector(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main()
{
    // 1. std::vector 생성
    // Vector3D 타입의 객체들을 저장할 수 있는 동적 배열 a_mesh_nodes를 생성합니다.
    // CAE 관점에서, 이는 유한요소해석(FEM)의 '메시(Mesh)의 절점(Node) 리스트'에 해당합니다.
    std::vector<Vector3D> a_mesh_nodes;

    // 2. vector에 요소 추가 (push_back)
    // .push_back() 멤버 함수는 vector의 맨 뒤에 새로운 요소를 추가합니다.
    // 벡터의 메모리 공간이 부족하면, 자동으로 더 큰 공간을 할당받아 이사가는 과정이 내부적으로 일어납니다.
    std::cout << "--- 절점 데이터 추가 시작 ---" << std::endl;
    a_mesh_nodes.push_back(Vector3D(1.0, 2.0, 0.0));
    a_mesh_nodes.push_back(Vector3D(3.0, 1.5, 2.0));
    a_mesh_nodes.push_back(Vector3D(5.0, 2.5, 1.0));

    // 3. vector의 크기 확인 (size)
    // .size() 멤버 함수는 현재 vector에 저장된 요소의 개수를 반환합니다.
    std::cout << "\n현재 메시에 등록된 절점 개수: " << a_mesh_nodes.size() << std::endl;

    // 4. vector의 모든 요소 순회 (Range-based for loop)
    // C++11부터 도입된 매우 편리한 반복문입니다.
    // for (const auto& node : a_mesh_nodes)
    // - a_mesh_nodes 컨테이너의 모든 원소를 처음부터 끝까지 순회합니다.
    // - 'node'는 각 순회마다 컨테이너의 원소(Vector3D 객체)를 가리킵니다.
    // - 'const&' (상수 참조)를 사용하는 이유:
    //   1) & (참조): 'node'에 객체를 복사하지 않고 원본을 직접 참조하므로 불필요한 복사 비용이 발생하지 않습니다. (성능 향상)
    //   2) const (상수): 반복문 내에서 원본 데이터를 실수로 변경하는 것을 막아줍니다. (안전성)
    std::cout << "\n--- 전체 절점 정보 출력 ---" << std::endl;
    for (const auto &node : a_mesh_nodes)
    {
        node.print();
    }

    // 5. 특정 조건의 요소 찾기
    // CAE 작업에서 매우 흔한 패턴: 수많은 데이터 중 특정 조건을 만족하는 데이터(들)를 찾는 과정.
    // 예: Z좌표가 0.0인 경계면의 절점들 찾기
    std::cout << "\n--- Z=0 평면의 경계 조건 절점 검색 ---" << std::endl;
    for (const auto &node : a_mesh_nodes)
    {
        if (node.z == 0.0)
        {
            std::cout << "경계면 절점 발견: ";
            node.print();
        }
    }

    return 0;
}