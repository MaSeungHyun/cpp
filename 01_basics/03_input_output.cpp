#include <iostream>
#include <string>

using namespace std;

int main() {
    // 기본 입력
    cout << "이름을 입력하세요: ";
    string name;
    cin >> name;
    
    cout << "나이를 입력하세요: ";
    int age;
    cin >> age;
    
    cout << "\n안녕하세요, " << name << "님!" << endl;
    cout << "나이가 " << age << "살이시군요!" << endl;
    
    // 공백을 포함한 문자열 입력
    cin.ignore(); // 버퍼 비우기
    cout << "\n좋아하는 문구를 입력하세요: ";
    string phrase;
    getline(cin, phrase);
    
    cout << "입력하신 문구: " << phrase << endl;
    
    // 여러 값 한 번에 입력받기
    cout << "\n두 개의 숫자를 입력하세요 (공백으로 구분): ";
    int num1, num2;
    cin >> num1 >> num2;
    
    cout << "입력하신 숫자: " << num1 << ", " << num2 << endl;
    cout << "합계: " << num1 + num2 << endl;
    
    return 0;
}

