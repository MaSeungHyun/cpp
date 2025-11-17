#include <iostream>
#include <cmath>

using namespace std;

// 복소수 클래스
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // 산술 연산자 오버로딩
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }
    
    // 비교 연산자
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }
    
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
    
    // 입출력 연산자 (friend 함수)
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
    
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) os << "+";
    os << c.imag << "i";
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    cout << "실수부: ";
    is >> c.real;
    cout << "허수부: ";
    is >> c.imag;
    return is;
}

// 벡터 클래스
class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}
    
    // 덧셈
    Vector2D operator+(const Vector2D& v) const {
        return Vector2D(x + v.x, y + v.y);
    }
    
    // 뺄셈
    Vector2D operator-(const Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }
    
    // 스칼라 곱셈
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }
    
    // 내적
    double dot(const Vector2D& v) const {
        return x * v.x + y * v.y;
    }
    
    // 단항 연산자 (부호 반전)
    Vector2D operator-() const {
        return Vector2D(-x, -y);
    }
    
    // 복합 대입 연산자
    Vector2D& operator+=(const Vector2D& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
    
    // 비교 연산자
    bool operator==(const Vector2D& v) const {
        return (x == v.x) && (y == v.y);
    }
    
    // 배열 접근 연산자
    double& operator[](int index) {
        return (index == 0) ? x : y;
    }
    
    friend ostream& operator<<(ostream& os, const Vector2D& v);
    
    double magnitude() const {
        return sqrt(x * x + y * y);
    }
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

// 카운터 클래스 (증감 연산자)
class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}
    
    // 전위 증가
    Counter& operator++() {
        ++count;
        return *this;
    }
    
    // 후위 증가
    Counter operator++(int) {
        Counter temp = *this;
        count++;
        return temp;
    }
    
    int getValue() const { return count; }
    
    friend ostream& operator<<(ostream& os, const Counter& c);
};

ostream& operator<<(ostream& os, const Counter& c) {
    os << c.count;
    return os;
}

int main() {
    cout << "=== 복소수 연산 ===" << endl;
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;
    cout << "|c1| = " << c1.magnitude() << endl;
    
    cout << "\n=== 벡터 연산 ===" << endl;
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * 2 = " << (v1 * 2) << endl;
    cout << "v1 · v2 = " << v1.dot(v2) << endl;
    cout << "-v1 = " << (-v1) << endl;
    cout << "|v1| = " << v1.magnitude() << endl;
    
    v1 += v2;
    cout << "v1 += v2: " << v1 << endl;
    
    cout << "v1[0] = " << v1[0] << ", v1[1] = " << v1[1] << endl;
    
    cout << "\n=== 증감 연산자 ===" << endl;
    Counter cnt(10);
    cout << "초기값: " << cnt << endl;
    cout << "++cnt: " << ++cnt << endl;
    cout << "cnt++: " << cnt++ << endl;
    cout << "최종값: " << cnt << endl;
    
    return 0;
}

