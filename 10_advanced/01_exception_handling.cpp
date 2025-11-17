#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// 기본 예외 처리
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("0으로 나눌 수 없습니다!");
    }
    return a / b;
}

// 사용자 정의 예외
class NegativeNumberException : public exception {
private:
    string message;
    
public:
    NegativeNumberException(const string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

double squareRoot(double x) {
    if (x < 0) {
        throw NegativeNumberException("음수의 제곱근을 구할 수 없습니다!");
    }
    return sqrt(x);
}

// 배열 접근
int getElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("인덱스가 범위를 벗어났습니다!");
    }
    return arr[index];
}

int main() {
    // 기본 예외 처리
    cout << "=== 기본 예외 처리 ===" << endl;
    try {
        cout << "10 / 2 = " << divide(10, 2) << endl;
        cout << "10 / 0 = " << divide(10, 0) << endl;  // 예외 발생
        cout << "이 줄은 실행되지 않습니다." << endl;
    } catch (const runtime_error& e) {
        cout << "오류 발생: " << e.what() << endl;
    }
    
    // 사용자 정의 예외
    cout << "\n=== 사용자 정의 예외 ===" << endl;
    try {
        cout << "sqrt(16) = " << squareRoot(16) << endl;
        cout << "sqrt(-4) = " << squareRoot(-4) << endl;  // 예외 발생
    } catch (const NegativeNumberException& e) {
        cout << "오류 발생: " << e.what() << endl;
    }
    
    // 여러 catch 블록
    cout << "\n=== 여러 예외 처리 ===" << endl;
    try {
        int arr[] = {1, 2, 3, 4, 5};
        cout << "arr[2] = " << getElement(arr, 5, 2) << endl;
        cout << "arr[10] = " << getElement(arr, 5, 10) << endl;  // 예외 발생
    } catch (const out_of_range& e) {
        cout << "범위 오류: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "일반 오류: " << e.what() << endl;
    }
    
    // 예외 재발생
    cout << "\n=== 예외 재발생 ===" << endl;
    try {
        try {
            throw runtime_error("내부 오류");
        } catch (const exception& e) {
            cout << "내부 catch: " << e.what() << endl;
            throw;  // 예외 재발생
        }
    } catch (const exception& e) {
        cout << "외부 catch: " << e.what() << endl;
    }
    
    // 모든 예외 잡기
    cout << "\n=== 모든 예외 ===" << endl;
    try {
        throw 42;  // int 타입 예외
    } catch (...) {
        cout << "알 수 없는 예외가 발생했습니다." << endl;
    }
    
    cout << "\n프로그램 정상 종료" << endl;
    
    return 0;
}

