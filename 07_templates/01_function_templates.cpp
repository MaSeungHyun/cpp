#include <iostream>
#include <string>

using namespace std;

// 기본 함수 템플릿
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// 여러 타입 매개변수
template <typename T, typename U>
void printPair(T first, U second) {
    cout << "(" << first << ", " << second << ")" << endl;
}

// 배열 출력 템플릿
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 스왑 함수
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// 합계 계산
template <typename T>
T sum(T arr[], int size) {
    T total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    cout << "=== 기본 템플릿 ===" << endl;
    cout << "max(10, 20) = " << maximum(10, 20) << endl;
    cout << "max(3.14, 2.71) = " << maximum(3.14, 2.71) << endl;
    cout << "max('a', 'z') = " << maximum('a', 'z') << endl;
    
    string s1 = "apple", s2 = "banana";
    cout << "max(\"apple\", \"banana\") = " << maximum(s1, s2) << endl;
    
    cout << "\n=== 여러 타입 매개변수 ===" << endl;
    printPair(10, 3.14);
    printPair("Hello", 42);
    printPair(true, "World");
    
    cout << "\n=== 배열 출력 ===" << endl;
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
    string strArr[] = {"Hello", "World", "C++"};
    
    printArray(intArr, 5);
    printArray(doubleArr, 4);
    printArray(strArr, 3);
    
    cout << "\n=== 스왑 ===" << endl;
    int x = 10, y = 20;
    cout << "교환 전: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "교환 후: x = " << x << ", y = " << y << endl;
    
    cout << "\n=== 합계 ===" << endl;
    cout << "정수 배열 합계: " << sum(intArr, 5) << endl;
    cout << "실수 배열 합계: " << sum(doubleArr, 4) << endl;
    
    return 0;
}

