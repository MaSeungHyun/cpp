/*
연습 문제를 여기에서 풀어보세요!

문제 1: 두 수를 입력받아 사칙연산 결과를 출력하는 프로그램 작성
문제 2: 이름과 나이를 입력받아 정보를 출력하는 프로그램 작성
문제 3: 섭씨 온도를 입력받아 화씨로 변환하는 프로그램 작성
        화씨 = 섭씨 × 9/5 + 32
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // 문제 1
    cout << "두 수를 입력하세요: ";
    int num1, num2;
    cin >> num1 >> num2;

    cout << "+ : " << num1 + num2 << endl;
    cout << "- : " << num1 - num2 << endl;
    cout << "* : " << num1 * num2 << endl;
    if(num2 != 0) {
        cout << "/ : " << num1 / num2 << endl;
    } else {
        cout << "/ : 0으로 나눌 수 없습니다." << endl;
    }
    
    // 문제 2
    cin.ignore();
    cout << "이름을 입력하세요: ";
    string name;
    getline(cin, name);
    cout << "나이를 입력하세요: ";
    int age;
    cin >> age;
    cout << "안녕하세요, " << name << "님! " << age << "살이시군요!" << endl;
    
    // 문제 3
    cout << "섭씨 온도를 입력하세요: ";
    double celsius;
    cin >> celsius;
    cout << "섭씨 " << celsius << "도는 화씨 " << celsius * 9/5 + 32 << "도 입니다." << endl;

    return 0;
}

