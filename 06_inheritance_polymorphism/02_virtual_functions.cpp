#include <iostream>
#include <string>

using namespace std;

// 가상 함수를 사용한 다형성
class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {}
    
    virtual ~Shape() {
        cout << "Shape 소멸: " << name << endl;
    }
    
    // 가상 함수
    virtual double getArea() const {
        return 0.0;
    }
    
    virtual void draw() const {
        cout << "도형을 그립니다." << endl;
    }
    
    void printInfo() const {
        cout << name << " - 넓이: " << getArea() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("원"), radius(r) {}
    
    ~Circle() {
        cout << "Circle 소멸" << endl;
    }
    
    // 가상 함수 오버라이딩
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    void draw() const override {
        cout << "원을 그립니다. (반지름: " << radius << ")" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : Shape("사각형"), width(w), height(h) {}
    
    ~Rectangle() {
        cout << "Rectangle 소멸" << endl;
    }
    
    double getArea() const override {
        return width * height;
    }
    
    void draw() const override {
        cout << "사각형을 그립니다. (" << width << " x " << height << ")" << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : Shape("삼각형"), base(b), height(h) {}
    
    ~Triangle() {
        cout << "Triangle 소멸" << endl;
    }
    
    double getArea() const override {
        return 0.5 * base * height;
    }
    
    void draw() const override {
        cout << "삼각형을 그립니다. (밑변: " << base << ", 높이: " << height << ")" << endl;
    }
};

// 다형성 활용 함수
void displayShape(const Shape& shape) {
    shape.printInfo();
    shape.draw();
    cout << endl;
}

int main() {
    cout << "=== 다형성 예제 ===" << endl;
    
    Circle circle(5.0);
    Rectangle rect(4.0, 6.0);
    Triangle tri(3.0, 4.0);
    
    // 각각의 객체로 직접 호출
    circle.printInfo();
    rect.printInfo();
    tri.printInfo();
    
    cout << "\n=== 다형성을 통한 호출 ===" << endl;
    displayShape(circle);
    displayShape(rect);
    displayShape(tri);
    
    cout << "=== 포인터를 통한 다형성 ===" << endl;
    Shape* shapes[3];
    shapes[0] = new Circle(10.0);
    shapes[1] = new Rectangle(5.0, 8.0);
    shapes[2] = new Triangle(6.0, 7.0);
    
    for (int i = 0; i < 3; i++) {
        shapes[i]->printInfo();
        shapes[i]->draw();
        cout << endl;
    }
    
    // 메모리 해제 (가상 소멸자가 있어야 올바르게 소멸됨)
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }
    
    return 0;
}

