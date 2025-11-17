#include <iostream>
#include <string>

using namespace std;

// 기본 클래스 (부모 클래스)
class Animal {
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {
        cout << "Animal 생성: " << name << endl;
    }
    
    ~Animal() {
        cout << "Animal 소멸: " << name << endl;
    }
    
    void eat() {
        cout << name << "이(가) 먹이를 먹습니다." << endl;
    }
    
    void sleep() {
        cout << name << "이(가) 잠을 잡니다." << endl;
    }
    
    void printInfo() {
        cout << "이름: " << name << ", 나이: " << age << "살" << endl;
    }
};

// 파생 클래스 (자식 클래스)
class Dog : public Animal {
private:
    string breed;

public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {
        cout << "Dog 생성: " << name << endl;
    }
    
    ~Dog() {
        cout << "Dog 소멸: " << name << endl;
    }
    
    void bark() {
        cout << name << ": 멍멍!" << endl;
    }
    
    void printInfo() {
        Animal::printInfo();  // 부모 클래스 함수 호출
        cout << "품종: " << breed << endl;
    }
};

class Cat : public Animal {
private:
    bool indoor;

public:
    Cat(string n, int a, bool i) : Animal(n, a), indoor(i) {
        cout << "Cat 생성: " << name << endl;
    }
    
    ~Cat() {
        cout << "Cat 소멸: " << name << endl;
    }
    
    void meow() {
        cout << name << ": 야옹~" << endl;
    }
    
    void printInfo() {
        Animal::printInfo();
        cout << "실내 고양이: " << (indoor ? "예" : "아니오") << endl;
    }
};

// 도형 클래스 계층
class Shape {
protected:
    string color;

public:
    Shape(string c) : color(c) {}
    
    void setColor(string c) {
        color = c;
    }
    
    string getColor() const {
        return color;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(string c, double w, double h) 
        : Shape(c), width(w), height(h) {}
    
    double getArea() {
        return width * height;
    }
    
    void printInfo() {
        cout << "사각형 - 색상: " << color 
             << ", 가로: " << width 
             << ", 세로: " << height 
             << ", 넓이: " << getArea() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string c, double r) : Shape(c), radius(r) {}
    
    double getArea() {
        return 3.14159 * radius * radius;
    }
    
    void printInfo() {
        cout << "원 - 색상: " << color 
             << ", 반지름: " << radius 
             << ", 넓이: " << getArea() << endl;
    }
};

int main() {
    cout << "=== Animal 상속 ===" << endl;
    {
        Dog dog("바둑이", 3, "진돗개");
        dog.printInfo();
        dog.eat();
        dog.bark();
        
        cout << endl;
        
        Cat cat("나비", 2, true);
        cat.printInfo();
        cat.sleep();
        cat.meow();
    }
    
    cout << "\n=== Shape 상속 ===" << endl;
    Rectangle rect("빨강", 10.0, 5.0);
    Circle circle("파랑", 7.0);
    
    rect.printInfo();
    circle.printInfo();
    
    rect.setColor("초록");
    rect.printInfo();
    
    return 0;
}

