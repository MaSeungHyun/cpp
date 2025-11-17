#include <iostream>

using namespace std;

int main() {
    // 기본 for 문
    cout << "=== 1부터 10까지 출력 ===" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // 짝수만 출력
    cout << "\n=== 1부터 20까지 짝수 출력 ===" << endl;
    for (int i = 2; i <= 20; i += 2) {
        cout << i << " ";
    }
    cout << endl;
    
    // 역순 출력
    cout << "\n=== 10부터 1까지 역순 출력 ===" << endl;
    for (int i = 10; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    
    // 합계 계산
    cout << "\n=== 1부터 100까지의 합 ===" << endl;
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    cout << "합계: " << sum << endl;
    
    // 구구단
    cout << "\n=== 5단 출력 ===" << endl;
    for (int i = 1; i <= 9; i++) {
        cout << "5 x " << i << " = " << (5 * i) << endl;
    }
    
    // break 사용
    cout << "\n=== break 예제 (5 이상이면 종료) ===" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i >= 5) {
            break;
        }
        cout << i << " ";
    }
    cout << endl;
    
    // continue 사용
    cout << "\n=== continue 예제 (3의 배수 제외) ===" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            continue;
        }
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}

