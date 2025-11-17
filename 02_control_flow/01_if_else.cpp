#include <iostream>

using namespace std;

int main() {
    // 기본 if 문
    cout << "=== 기본 if 문 ===" << endl;
    int age;
    cout << "나이를 입력하세요: ";
    cin >> age;
    
    if (age >= 20) {
        cout << "성인입니다." << endl;
    }
    
    // if-else 문
    cout << "\n=== if-else 문 ===" << endl;
    int num;
    cout << "숫자를 입력하세요: ";
    cin >> num;
    
    if (num % 2 == 0) {
        cout << num << "은(는) 짝수입니다." << endl;
    } else {
        cout << num << "은(는) 홀수입니다." << endl;
    }
    
    // if-else if-else 문
    cout << "\n=== if-else if-else 문 ===" << endl;
    int score;
    cout << "점수를 입력하세요 (0-100): ";
    cin >> score;
    
    if (score >= 90) {
        cout << "학점: A" << endl;
    } else if (score >= 80) {
        cout << "학점: B" << endl;
    } else if (score >= 70) {
        cout << "학점: C" << endl;
    } else if (score >= 60) {
        cout << "학점: D" << endl;
    } else {
        cout << "학점: F" << endl;
    }
    
    // 중첩 if 문
    cout << "\n=== 중첩 if 문 ===" << endl;
    int temperature;
    bool isRaining;
    cout << "온도를 입력하세요: ";
    cin >> temperature;
    cout << "비가 오나요? (1: 예, 0: 아니오): ";
    cin >> isRaining;
    
    if (temperature > 25) {
        if (isRaining) {
            cout << "더운데 비가 오네요. 습합니다!" << endl;
        } else {
            cout << "더운 날씨입니다. 시원한 곳을 찾으세요!" << endl;
        }
    } else {
        if (isRaining) {
            cout << "비가 오네요. 우산을 챙기세요!" << endl;
        } else {
            cout << "쾌적한 날씨입니다!" << endl;
        }
    }
    
    return 0;
}

