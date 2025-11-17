#include <iostream>

using namespace std;

// 값에 의한 전달 (Pass by Value)
void incrementByValue(int x) {
    x++;
    cout << "함수 내부 (값 전달): " << x << endl;
}

// 참조에 의한 전달 (Pass by Reference)
void incrementByReference(int& x) {
    x++;
    cout << "함수 내부 (참조 전달): " << x << endl;
}

// 두 값 교환 (값 전달) - 작동하지 않음
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 두 값 교환 (참조 전달) - 올바른 방법
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 여러 값 반환하기 (참조 사용)
void divideWithRemainder(int dividend, int divisor, int& quotient, int& remainder) {
    quotient = dividend / divisor;
    remainder = dividend % divisor;
}

// 배열을 참조로 전달
void doubleArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// const 참조 (읽기 전용)
void printValue(const int& x) {
    cout << "값: " << x << endl;
    // x++; // 오류! const 참조는 수정 불가
}

int main() {
    // 값 전달 vs 참조 전달
    cout << "=== 값 전달 vs 참조 전달 ===" << endl;
    int num1 = 10;
    cout << "원본 값: " << num1 << endl;
    incrementByValue(num1);
    cout << "함수 호출 후 (값 전달): " << num1 << endl;
    
    cout << endl;
    int num2 = 10;
    cout << "원본 값: " << num2 << endl;
    incrementByReference(num2);
    cout << "함수 호출 후 (참조 전달): " << num2 << endl;
    
    // 값 교환
    cout << "\n=== 값 교환 ===" << endl;
    int a = 5, b = 10;
    cout << "교환 전: a = " << a << ", b = " << b << endl;
    swapByValue(a, b);
    cout << "값 전달 후: a = " << a << ", b = " << b << endl;
    
    swapByReference(a, b);
    cout << "참조 전달 후: a = " << a << ", b = " << b << endl;
    
    // 여러 값 반환
    cout << "\n=== 여러 값 반환 ===" << endl;
    int quotient, remainder;
    divideWithRemainder(17, 5, quotient, remainder);
    cout << "17 ÷ 5 = " << quotient << " ... " << remainder << endl;
    
    // 배열 수정
    cout << "\n=== 배열 수정 ===" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    cout << "원본 배열: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    doubleArray(arr, 5);
    cout << "2배 후 배열: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // const 참조
    cout << "\n=== const 참조 ===" << endl;
    int value = 42;
    printValue(value);
    
    return 0;
}

