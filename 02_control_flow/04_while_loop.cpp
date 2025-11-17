#include <iostream>

using namespace std;

int main() {
    // 기본 while 문
    cout << "=== while 문 예제 ===" << endl;
    int i = 1;
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    cout << endl;
    
    // 합계 계산
    cout << "\n=== 1부터 10까지의 합 ===" << endl;
    int sum = 0;
    int num = 1;
    while (num <= 10) {
        sum += num;
        num++;
    }
    cout << "합계: " << sum << endl;
    
    // 사용자 입력 받기
    cout << "\n=== 0을 입력할 때까지 합계 ===" << endl;
    int input;
    int total = 0;
    cout << "숫자를 입력하세요 (0: 종료): ";
    cin >> input;
    
    while (input != 0) {
        total += input;
        cout << "숫자를 입력하세요 (0: 종료): ";
        cin >> input;
    }
    cout << "합계: " << total << endl;
    
    // do-while 문
    cout << "\n=== do-while 문 예제 ===" << endl;
    int choice;
    do {
        cout << "\n메뉴를 선택하세요:" << endl;
        cout << "1. 안녕하세요" << endl;
        cout << "2. 반갑습니다" << endl;
        cout << "3. 종료" << endl;
        cout << "선택: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "안녕하세요!" << endl;
                break;
            case 2:
                cout << "반갑습니다!" << endl;
                break;
            case 3:
                cout << "프로그램을 종료합니다." << endl;
                break;
            default:
                cout << "잘못된 선택입니다." << endl;
        }
    } while (choice != 3);
    
    return 0;
}

