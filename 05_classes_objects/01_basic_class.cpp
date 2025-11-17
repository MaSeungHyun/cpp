#include <iostream>
#include <string>

using namespace std;

// 간단한 클래스 정의
class Person {
public:
    // 멤버 변수
    string name;
    int age;
    
    // 멤버 함수
    void introduce() {
        cout << "안녕하세요, 제 이름은 " << name << "이고 " << age << "살입니다." << endl;
    }
    
    void haveBirthday() {
        age++;
        cout << "생일을 맞았습니다! 이제 " << age << "살입니다." << endl;
    }
};

// 좀 더 복잡한 클래스
class Rectangle {
public:
    double width;
    double height;
    
    // 넓이 계산
    double getArea() {
        return width * height;
    }
    
    // 둘레 계산
    double getPerimeter() {
        return 2 * (width + height);
    }
    
    // 정보 출력
    void printInfo() {
        cout << "가로: " << width << ", 세로: " << height << endl;
        cout << "넓이: " << getArea() << endl;
        cout << "둘레: " << getPerimeter() << endl;
    }
};

// 메서드를 클래스 외부에 정의
class Circle {
public:
    double radius;
    
    double getArea();
    double getCircumference();
    void printInfo();
};

double Circle::getArea() {
    return 3.14159 * radius * radius;
}

double Circle::getCircumference() {
    return 2 * 3.14159 * radius;
}

void Circle::printInfo() {
    cout << "반지름: " << radius << endl;
    cout << "넓이: " << getArea() << endl;
    cout << "둘레: " << getCircumference() << endl;
}

int main() {
    // 객체 생성
    cout << "=== Person 클래스 ===" << endl;
    Person person1;
    person1.name = "홍길동";
    person1.age = 25;
    person1.introduce();
    person1.haveBirthday();
    
    Person person2;
    person2.name = "김철수";
    person2.age = 30;
    person2.introduce();
    
    // Rectangle 객체
    cout << "\n=== Rectangle 클래스 ===" << endl;
    Rectangle rect;
    rect.width = 10.0;
    rect.height = 5.0;
    rect.printInfo();
    
    // Circle 객체
    cout << "\n=== Circle 클래스 ===" << endl;
    Circle circle;
    circle.radius = 7.0;
    circle.printInfo();
    
    // 여러 객체 생성
    cout << "\n=== 여러 객체 ===" << endl;
    Rectangle squares[3];
    for (int i = 0; i < 3; i++) {
        squares[i].width = (i + 1) * 2.0;
        squares[i].height = (i + 1) * 2.0;
        cout << "사각형 " << (i + 1) << ":" << endl;
        squares[i].printInfo();
        cout << endl;
    }
    
    return 0;
}

