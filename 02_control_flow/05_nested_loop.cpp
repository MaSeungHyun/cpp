#include <iostream>

using namespace std;

int main() {
    // 구구단 전체 출력
    cout << "=== 구구단 (2단~9단) ===" << endl;
    for (int i = 2; i <= 9; i++) {
        cout << "\n[ " << i << "단 ]" << endl;
        for (int j = 1; j <= 9; j++) {
            cout << i << " x " << j << " = " << (i * j) << endl;
        }
    }
    
    // 별 찍기 패턴 1
    cout << "\n=== 별 찍기 패턴 1 ===" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // 별 찍기 패턴 2
    cout << "\n=== 별 찍기 패턴 2 ===" << endl;
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // 별 찍기 패턴 3 (피라미드)
    cout << "\n=== 별 찍기 패턴 3 (피라미드) ===" << endl;
    int height = 5;
    for (int i = 1; i <= height; i++) {
        // 공백 출력
        for (int j = 1; j <= height - i; j++) {
            cout << " ";
        }
        // 별 출력
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // 숫자 패턴
    cout << "\n=== 숫자 패턴 ===" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}

