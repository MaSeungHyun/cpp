#include <iostream>

using namespace std;

int main() {
    // switch 문 기본
    cout << "=== 계절 판별 ===" << endl;
    int month;
    cout << "월을 입력하세요 (1-12): ";
    cin >> month;
    
    switch (month) {
        case 12:
        case 1:
        case 2:
            cout << "겨울입니다." << endl;
            break;
        case 3:
        case 4:
        case 5:
            cout << "봄입니다." << endl;
            break;
        case 6:
        case 7:
        case 8:
            cout << "여름입니다." << endl;
            break;
        case 9:
        case 10:
        case 11:
            cout << "가을입니다." << endl;
            break;
        default:
            cout << "잘못된 입력입니다." << endl;
    }
    
    // 간단한 계산기
    cout << "\n=== 간단한 계산기 ===" << endl;
    double a, b;
    char op;
    
    cout << "첫 번째 숫자: ";
    cin >> a;
    cout << "연산자 (+, -, *, /): ";
    cin >> op;
    cout << "두 번째 숫자: ";
    cin >> b;
    
    switch (op) {
        case '+':
            cout << "결과: " << (a + b) << endl;
            break;
        case '-':
            cout << "결과: " << (a - b) << endl;
            break;
        case '*':
            cout << "결과: " << (a * b) << endl;
            break;
        case '/':
            if (b != 0) {
                cout << "결과: " << (a / b) << endl;
            } else {
                cout << "0으로 나눌 수 없습니다." << endl;
            }
            break;
        default:
            cout << "잘못된 연산자입니다." << endl;
    }
    
    return 0;
}

