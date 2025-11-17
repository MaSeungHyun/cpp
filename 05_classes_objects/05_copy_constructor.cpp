#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 복사 생성자 기본
class Point {
private:
    int x, y;

public:
    // 생성자
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {
        cout << "생성자 호출: (" << x << ", " << y << ")" << endl;
    }
    
    // 복사 생성자 (자동으로 생성되지만 명시적으로 정의)
    Point(const Point& other) : x(other.x), y(other.y) {
        cout << "복사 생성자 호출: (" << x << ", " << y << ")" << endl;
    }
    
    // 소멸자
    ~Point() {
        cout << "소멸자 호출: (" << x << ", " << y << ")" << endl;
    }
    
    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};

// 얕은 복사 vs 깊은 복사
class ShallowCopy {
private:
    int* data;
    int size;

public:
    ShallowCopy(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
        cout << "ShallowCopy 생성 (크기: " << size << ")" << endl;
    }
    
    // 기본 복사 생성자 사용 시 얕은 복사 발생 (포인터만 복사)
    // ShallowCopy(const ShallowCopy& other) = default;
    
    ~ShallowCopy() {
        cout << "ShallowCopy 소멸" << endl;
        delete[] data;
    }
    
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

class DeepCopy {
private:
    int* data;
    int size;

public:
    DeepCopy(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
        cout << "DeepCopy 생성 (크기: " << size << ")" << endl;
    }
    
    // 깊은 복사 생성자: 메모리를 새로 할당하고 값을 복사
    DeepCopy(const DeepCopy& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "DeepCopy 복사 생성자 호출 (크기: " << size << ")" << endl;
    }
    
    ~DeepCopy() {
        cout << "DeepCopy 소멸" << endl;
        delete[] data;
    }
    
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
    void modify(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }
};

// 문자열 클래스 구현
class MyString {
private:
    char* str;
    int length;

public:
    // 생성자
    MyString(const char* s = "") {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
        cout << "MyString 생성: \"" << str << "\"" << endl;
    }
    
    // 복사 생성자 (깊은 복사)
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        cout << "MyString 복사: \"" << str << "\"" << endl;
    }
    
    // 소멸자
    ~MyString() {
        cout << "MyString 소멸: \"" << str << "\"" << endl;
        delete[] str;
    }
    
    void print() const {
        cout << str << endl;
    }
    
    int getLength() const {
        return length;
    }
};

// 함수에 객체 전달 (복사 생성자 호출)
void printPoint(Point p) {
    cout << "함수 내부: ";
    p.print();
}

Point createPoint(int x, int y) {
    Point p(x, y);
    return p;  // 복사 생성자 호출 (또는 RVO로 최적화)
}

int main() {
    cout << "=== Point 복사 생성자 ===" << endl;
    Point p1(3, 4);
    Point p2 = p1;  // 복사 생성자 호출
    Point p3(p1);   // 복사 생성자 호출
    
    p1.print();
    p2.print();
    
    p1.move(1, 1);
    cout << "p1 이동 후:" << endl;
    p1.print();
    p2.print();  // p2는 영향받지 않음
    
    cout << "\n=== 함수와 복사 생성자 ===" << endl;
    printPoint(p1);
    
    Point p4 = createPoint(10, 20);
    
    cout << "\n=== 깊은 복사 ===" << endl;
    {
        DeepCopy dc1(5);
        cout << "dc1: ";
        dc1.print();
        
        DeepCopy dc2 = dc1;  // 복사 생성자 호출
        cout << "dc2 (복사본): ";
        dc2.print();
        
        dc1.modify(2, 999);
        cout << "dc1 수정 후: ";
        dc1.print();
        cout << "dc2 (독립적): ";
        dc2.print();
    }
    
    cout << "\n=== MyString 클래스 ===" << endl;
    {
        MyString s1("Hello");
        MyString s2 = s1;  // 복사 생성자
        MyString s3("World");
        
        s1.print();
        s2.print();
        s3.print();
    }
    
    cout << "\n프로그램 종료" << endl;
    
    return 0;
}

