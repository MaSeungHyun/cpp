#include <iostream>
#include <string>

using namespace std;

// static 멤버 변수와 함수
class Counter {
private:
    static int count;  // 모든 객체가 공유하는 변수
    int id;

public:
    Counter() {
        count++;
        id = count;
        cout << "Counter 객체 생성 (ID: " << id << ")" << endl;
    }
    
    ~Counter() {
        cout << "Counter 객체 소멸 (ID: " << id << ")" << endl;
        count--;
    }
    
    // static 멤버 함수
    static int getCount() {
        return count;
    }
    
    int getID() const {
        return id;
    }
};

// static 멤버 변수 초기화 (클래스 외부에서)
int Counter::count = 0;

// 은행 계좌 클래스 - 계좌 번호 자동 생성
class BankAccount {
private:
    static int nextAccountNumber;
    int accountNumber;
    string owner;
    double balance;

public:
    BankAccount(string own, double initialBalance = 0) 
        : accountNumber(nextAccountNumber++), owner(own), balance(initialBalance) {
        cout << "계좌 개설: " << owner << " (계좌번호: " << accountNumber << ")" << endl;
    }
    
    static int getTotalAccounts() {
        return nextAccountNumber - 1000;
    }
    
    void printInfo() const {
        cout << "소유자: " << owner << ", 계좌번호: " << accountNumber 
             << ", 잔액: " << balance << "원" << endl;
    }
};

int BankAccount::nextAccountNumber = 1000;

// 학생 클래스 - 총 학생 수 추적
class Student {
private:
    static int totalStudents;
    static double totalGPA;
    
    string name;
    double gpa;

public:
    Student(string n, double g) : name(n), gpa(g) {
        totalStudents++;
        totalGPA += gpa;
        cout << "학생 등록: " << name << endl;
    }
    
    ~Student() {
        totalStudents--;
        totalGPA -= gpa;
    }
    
    static int getTotalStudents() {
        return totalStudents;
    }
    
    static double getAverageGPA() {
        if (totalStudents == 0) return 0.0;
        return totalGPA / totalStudents;
    }
    
    void printInfo() const {
        cout << "이름: " << name << ", GPA: " << gpa << endl;
    }
};

int Student::totalStudents = 0;
double Student::totalGPA = 0.0;

// const 멤버 함수
class Circle {
private:
    double radius;
    mutable int accessCount;  // const 함수에서도 수정 가능

public:
    Circle(double r) : radius(r), accessCount(0) {}
    
    // const 멤버 함수: 객체의 상태를 변경하지 않음
    double getArea() const {
        accessCount++;  // mutable이므로 가능
        return 3.14159 * radius * radius;
    }
    
    double getRadius() const {
        accessCount++;
        return radius;
    }
    
    int getAccessCount() const {
        return accessCount;
    }
    
    // non-const 멤버 함수
    void setRadius(double r) {
        radius = r;
    }
};

int main() {
    cout << "=== Counter 클래스 ===" << endl;
    cout << "현재 Counter 수: " << Counter::getCount() << endl;
    
    {
        Counter c1, c2, c3;
        cout << "현재 Counter 수: " << Counter::getCount() << endl;
        
        Counter c4;
        cout << "현재 Counter 수: " << Counter::getCount() << endl;
    }  // 블록을 벗어나면 소멸자 호출
    
    cout << "현재 Counter 수: " << Counter::getCount() << endl;
    
    cout << "\n=== BankAccount 클래스 ===" << endl;
    BankAccount acc1("홍길동", 100000);
    BankAccount acc2("김철수", 200000);
    BankAccount acc3("이영희", 150000);
    
    cout << "총 개설된 계좌 수: " << BankAccount::getTotalAccounts() << endl;
    
    acc1.printInfo();
    acc2.printInfo();
    acc3.printInfo();
    
    cout << "\n=== Student 클래스 ===" << endl;
    {
        Student s1("Alice", 3.8);
        Student s2("Bob", 3.5);
        Student s3("Charlie", 4.0);
        
        cout << "총 학생 수: " << Student::getTotalStudents() << endl;
        cout << "평균 GPA: " << Student::getAverageGPA() << endl;
        
        s1.printInfo();
        s2.printInfo();
        s3.printInfo();
    }
    
    cout << "총 학생 수: " << Student::getTotalStudents() << endl;
    
    cout << "\n=== const 멤버 함수 ===" << endl;
    const Circle circle(5.0);
    cout << "반지름: " << circle.getRadius() << endl;
    cout << "넓이: " << circle.getArea() << endl;
    // circle.setRadius(10);  // 오류! const 객체는 non-const 함수 호출 불가
    
    cout << "접근 횟수: " << circle.getAccessCount() << endl;
    
    return 0;
}

