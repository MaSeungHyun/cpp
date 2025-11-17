#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// auto 키워드
void autoExample() {
    cout << "=== auto 키워드 ===" << endl;
    
    auto i = 10;              // int
    auto d = 3.14;            // double
    auto s = string("Hello"); // string
    auto v = vector<int>{1, 2, 3, 4, 5};  // vector<int>
    
    cout << "i: " << i << " (int)" << endl;
    cout << "d: " << d << " (double)" << endl;
    cout << "s: " << s << " (string)" << endl;
    
    // auto와 반복자
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// 범위 기반 for 루프
void rangeForExample() {
    cout << "\n=== 범위 기반 for 루프 ===" << endl;
    
    vector<int> numbers = {1, 2, 3, 4, 5};
    
    // 값으로
    cout << "값으로: ";
    for (auto num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // 참조로 (수정 가능)
    for (auto& num : numbers) {
        num *= 2;
    }
    
    cout << "2배 후: ";
    for (const auto& num : numbers) {  // const 참조
        cout << num << " ";
    }
    cout << endl;
}

// nullptr
void nullptrExample() {
    cout << "\n=== nullptr ===" << endl;
    
    int* ptr1 = nullptr;  // nullptr (C++11)
    // int* ptr2 = NULL;  // NULL (구식)
    
    if (ptr1 == nullptr) {
        cout << "ptr1은 null입니다." << endl;
    }
    
    int x = 10;
    ptr1 = &x;
    
    if (ptr1 != nullptr) {
        cout << "*ptr1 = " << *ptr1 << endl;
    }
}

// constexpr
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

void constexprExample() {
    cout << "\n=== constexpr ===" << endl;
    
    constexpr int x = 5;
    constexpr int result = factorial(5);  // 컴파일 타임에 계산
    
    cout << "5! = " << result << endl;
}

// 초기화 리스트
void initializerListExample() {
    cout << "\n=== 초기화 리스트 ===" << endl;
    
    // 균일 초기화
    int a{10};
    double b{3.14};
    
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2{10, 20, 30};
    
    cout << "v2: ";
    for (auto num : v2) {
        cout << num << " ";
    }
    cout << endl;
}

// 람다 함수
void lambdaExample() {
    cout << "\n=== 람다 함수 ===" << endl;
    
    vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    // 정렬 (내림차순)
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });
    
    cout << "내림차순: ";
    for (auto num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // 조건에 맞는 개수
    int count = count_if(numbers.begin(), numbers.end(), [](int n) {
        return n >= 5;
    });
    cout << "5 이상: " << count << "개" << endl;
}

// using (타입 별칭)
using IntVector = vector<int>;
using StringMap = map<string, int>;

void typeAliasExample() {
    cout << "\n=== 타입 별칭 ===" << endl;
    
    IntVector v = {1, 2, 3, 4, 5};
    cout << "IntVector 크기: " << v.size() << endl;
}

int main() {
    autoExample();
    rangeForExample();
    nullptrExample();
    constexprExample();
    initializerListExample();
    lambdaExample();
    typeAliasExample();
    
    return 0;
}

