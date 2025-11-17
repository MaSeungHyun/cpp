#include <iostream>

using namespace std;

int main() {
    // 산술 연산자
    cout << "=== 산술 연산자 ===" << endl;
    int a = 10, b = 3;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a % b = " << (a % b) << endl;
    
    // 증감 연산자
    cout << "\n=== 증감 연산자 ===" << endl;
    int x = 5;
    cout << "x = " << x << endl;
    cout << "x++ = " << x++ << endl; // 5 출력 후 증가
    cout << "x = " << x << endl;     // 6
    cout << "++x = " << ++x << endl; // 증가 후 7 출력
    
    // 비교 연산자
    cout << "\n=== 비교 연산자 ===" << endl;
    cout << "10 == 10: " << (10 == 10) << endl;
    cout << "10 != 5: " << (10 != 5) << endl;
    cout << "10 > 5: " << (10 > 5) << endl;
    cout << "5 < 10: " << (5 < 10) << endl;
    
    // 논리 연산자
    cout << "\n=== 논리 연산자 ===" << endl;
    bool p = true, q = false;
    cout << "p = " << p << ", q = " << q << endl;
    cout << "p && q = " << (p && q) << endl;
    cout << "p || q = " << (p || q) << endl;
    cout << "!p = " << (!p) << endl;
    
    // 복합 대입 연산자
    cout << "\n=== 복합 대입 연산자 ===" << endl;
    int num = 10;
    cout << "num = " << num << endl;
    num += 5;  // num = num + 5
    cout << "num += 5: " << num << endl;
    num -= 3;  // num = num - 3
    cout << "num -= 3: " << num << endl;
    num *= 2;  // num = num * 2
    cout << "num *= 2: " << num << endl;
    num /= 4;  // num = num / 4
    cout << "num /= 4: " << num << endl;
    
    return 0;
}

