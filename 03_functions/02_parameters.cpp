#include <iostream>
#include <string>

using namespace std;

// 기본 매개변수 (default parameter)
void printMessage(string message = "기본 메시지") {
    cout << message << endl;
}

// 여러 개의 기본 매개변수
int power(int base, int exponent = 2) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// 다양한 반환 타입
string getDayName(int day) {
    switch (day) {
        case 1: return "월요일";
        case 2: return "화요일";
        case 3: return "수요일";
        case 4: return "목요일";
        case 5: return "금요일";
        case 6: return "토요일";
        case 7: return "일요일";
        default: return "잘못된 입력";
    }
}

// 조기 반환 (early return)
int getAbsolute(int num) {
    if (num >= 0) {
        return num;
    }
    return -num;
}

// 복잡한 계산 함수
double calculateBMI(double weight, double height) {
    // BMI = 체중(kg) / 키(m)^2
    return weight / (height * height);
}

int main() {
    cout << "=== 기본 매개변수 ===" << endl;
    printMessage();  // 기본값 사용
    printMessage("안녕하세요!");  // 인자 전달
    
    cout << "\n=== 거듭제곱 계산 ===" << endl;
    cout << "5^2 = " << power(5) << endl;  // 기본값 사용
    cout << "2^3 = " << power(2, 3) << endl;  // 인자 전달
    cout << "3^4 = " << power(3, 4) << endl;
    
    cout << "\n=== 요일 이름 ===" << endl;
    for (int i = 1; i <= 7; i++) {
        cout << i << "일: " << getDayName(i) << endl;
    }
    
    cout << "\n=== 절댓값 ===" << endl;
    cout << "abs(-5) = " << getAbsolute(-5) << endl;
    cout << "abs(10) = " << getAbsolute(10) << endl;
    
    cout << "\n=== BMI 계산 ===" << endl;
    double weight = 70.0;  // kg
    double height = 1.75;  // m
    double bmi = calculateBMI(weight, height);
    cout << "체중: " << weight << "kg, 키: " << height << "m" << endl;
    cout << "BMI: " << bmi << endl;
    
    return 0;
}

