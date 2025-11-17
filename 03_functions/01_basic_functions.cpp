#include <iostream>

using namespace std;

// 반환값이 없는 함수 (void)
void greet() {
    cout << "안녕하세요!" << endl;
}

// 매개변수가 있는 함수
void greetWithName(string name) {
    cout << "안녕하세요, " << name << "님!" << endl;
}

// 반환값이 있는 함수
int add(int a, int b) {
    return a + b;
}

// 여러 개의 매개변수
int multiply(int a, int b, int c) {
    return a * b * c;
}

// 실수 반환 함수
double divide(double a, double b) {
    if (b == 0) {
        cout << "오류: 0으로 나눌 수 없습니다." << endl;
        return 0;
    }
    return a / b;
}

// 불린 반환 함수
bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    // 함수 호출
    cout << "=== 기본 함수 호출 ===" << endl;
    greet();
    
    cout << "\n=== 매개변수가 있는 함수 ===" << endl;
    greetWithName("홍길동");
    greetWithName("김철수");
    
    cout << "\n=== 반환값이 있는 함수 ===" << endl;
    int sum = add(10, 20);
    cout << "10 + 20 = " << sum << endl;
    
    cout << "\n=== 여러 매개변수 ===" << endl;
    int result = multiply(2, 3, 4);
    cout << "2 × 3 × 4 = " << result << endl;
    
    cout << "\n=== 나눗셈 ===" << endl;
    double quotient = divide(10.0, 3.0);
    cout << "10 ÷ 3 = " << quotient << endl;
    
    cout << "\n=== 짝수 판별 ===" << endl;
    int num = 7;
    if (isEven(num)) {
        cout << num << "은(는) 짝수입니다." << endl;
    } else {
        cout << num << "은(는) 홀수입니다." << endl;
    }
    
    return 0;
}

