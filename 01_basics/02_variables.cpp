#include <iostream>
#include <string>

using namespace std;

int main() {
    // 정수형 변수
    int age = 25;
    long population = 51000000;
    short temperature = -5;
    
    // 실수형 변수
    float height = 175.5f;
    double pi = 3.14159265359;
    
    // 문자형 변수
    char grade = 'A';
    
    // 불린형 변수
    bool isStudent = true;
    
    // 문자열 변수
    string name = "홍길동";
    
    // 변수 출력
    cout << "=== 변수와 자료형 예제 ===" << endl;
    cout << "나이: " << age << endl;
    cout << "인구: " << population << endl;
    cout << "온도: " << temperature << "도" << endl;
    cout << "키: " << height << "cm" << endl;
    cout << "원주율: " << pi << endl;
    cout << "학점: " << grade << endl;
    cout << "학생 여부: " << isStudent << endl;
    cout << "이름: " << name << endl;
    
    // 변수 크기 확인
    cout << "\n=== 자료형 크기 ===" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "long: " << sizeof(long) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;
    
    return 0;
}

