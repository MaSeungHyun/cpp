#include <iostream>
#include <string>

using namespace std;

// 함수 오버로딩 (Function Overloading)
// 같은 이름, 다른 매개변수

// 정수 2개 더하기
int add(int a, int b) {
    cout << "int add 호출" << endl;
    return a + b;
}

// 실수 2개 더하기
double add(double a, double b) {
    cout << "double add 호출" << endl;
    return a + b;
}

// 정수 3개 더하기
int add(int a, int b, int c) {
    cout << "int add (3개) 호출" << endl;
    return a + b + c;
}

// print 함수 오버로딩
void print(int value) {
    cout << "정수: " << value << endl;
}

void print(double value) {
    cout << "실수: " << value << endl;
}

void print(string value) {
    cout << "문자열: " << value << endl;
}

void print(char value) {
    cout << "문자: " << value << endl;
}

// max 함수 오버로딩
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    int temp = (a > b) ? a : b;
    return (temp > c) ? temp : c;
}

int main() {
    cout << "=== 함수 오버로딩 - add ===" << endl;
    cout << "add(5, 3) = " << add(5, 3) << endl;
    cout << "add(5.5, 3.2) = " << add(5.5, 3.2) << endl;
    cout << "add(1, 2, 3) = " << add(1, 2, 3) << endl;
    
    cout << "\n=== 함수 오버로딩 - print ===" << endl;
    print(100);
    print(3.14);
    print("Hello");
    print('A');
    
    cout << "\n=== 함수 오버로딩 - max ===" << endl;
    cout << "max(10, 20) = " << max(10, 20) << endl;
    cout << "max(3.14, 2.71) = " << max(3.14, 2.71) << endl;
    cout << "max(5, 10, 3) = " << max(5, 10, 3) << endl;
    
    return 0;
}

