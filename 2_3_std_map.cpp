#include <iostream>
#include <string>
#include <map> // std::map을 사용하기 위해 반드시 포함해야 하는 헤더

// CAE에서 특정 경계면의 조건을 표현하는 간단한 구조체라고 가정합니다.
struct BoundaryCondition
{
    std::string type; // "fixedValue", "zeroGradient" 등 조건의 타입
    float value;      // 조건에 사용될 값 (예: 속도 3.0 m/s)
};

int main()
{
    // 1. std::map 생성
    // Key 타입은 std::string (경계면 이름), Value 타입은 BoundaryCondition (경계 조건 정보)
    std::map<std::string, BoundaryCondition> bc_map;

    // 2. map에 요소 추가
    // 가장 직관적인 방법은 [] 연산자를 사용하는 것입니다.
    bc_map["inlet"] = {"fixedValue", 5.0f};
    bc_map["outlet"] = {"zeroGradient", 0.0f};
    bc_map["wall"] = {"fixedValue", 0.0f}; // 벽면에서는 속도가 0이라는 의미 (No-slip condition)

    // 3. Key를 이용해 Value에 접근하기
    std::cout << "--- 'inlet' 경계면의 조건 확인 ---" << std::endl;
    BoundaryCondition inlet_bc = bc_map["inlet"];
    std::cout << "Type: " << inlet_bc.type << ", Value: " << inlet_bc.value << std::endl;

    // 4. map의 모든 요소 순회
    // 이터레이션 시, map은 자동으로 Key를 기준으로 오름차순 정렬하여 순회합니다. (inlet -> outlet -> wall)
    // 이 때 auto& pair의 실제 타입은 std::pair<const std::string, BoundaryCondition> 입니다.
    // .first로 Key에, .second로 Value에 접근할 수 있습니다.
    std::cout << "\n--- 전체 경계 조건 목록 (자동 정렬) ---" << std::endl;
    for (const auto& pair : bc_map)
    {
        std::cout << "경계면 이름(Key): " << pair.first
                  << " -> 조건 타입(Value.type): " << pair.second.type
                  << std::endl;
    }

    // 5. 특정 Key가 존재하는지 확인 (매우 중요!)
    // [] 연산자로 존재하지 않는 키("top")에 접근하면, 해당 키가 자동으로 생성되어 버립니다.
    // 이를 방지하려면, .find()를 사용해 키가 존재하는지 먼저 확인하는 것이 안전합니다.
    std::string search_key = "wing_surface";

    // bc_map.find(key)는 key를 찾으면 해당 이터레이터를, 못 찾으면 bc_map.end()를 반환합니다.
    // true, false를 반환하는게 아니기 때문에 이렇게 조건을 작성해야 함
    if (bc_map.find(search_key) != bc_map.end())
    {
        // bc_map.find(search_key)가 반환한게 end가 아니라면(즉 이터레이터를 찾았다면)
        std::cout << "\n'" << search_key << "' 경계 조건을 찾았습니다." << std::endl;
    }
    else
    {
        // bc_map.find(search_key)가 반환한게 end라면
        std::cout << "\n'" << search_key << "' 경계 조건은 목록에 없습니다." << std::endl;
    }

    return 0;
}