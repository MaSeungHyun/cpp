#include <iostream>
#include <string>

using namespace std;

// 생성자와 소멸자
class Student {
private:
    string name;
    int id;
    double gpa;

public:
    // 기본 생성자
    Student() {
        name = "Unknown";
        id = 0;
        gpa = 0.0;
        cout << "기본 생성자 호출: " << name << endl;
    }
    
    // 매개변수가 있는 생성자
    Student(string n, int i, double g) {
        name = n;
        id = i;
        gpa = g;
        cout << "매개변수 생성자 호출: " << name << endl;
    }
    
    // 소멸자
    ~Student() {
        cout << "소멸자 호출: " << name << endl;
    }
    
    void printInfo() {
        cout << "이름: " << name << ", ID: " << id << ", GPA: " << gpa << endl;
    }
};

// 초기화 리스트를 사용하는 생성자
class Point {
private:
    int x;
    int y;

public:
    // 초기화 리스트 사용
    Point() : x(0), y(0) {
        cout << "Point 기본 생성자" << endl;
    }
    
    Point(int x_val, int y_val) : x(x_val), y(y_val) {
        cout << "Point 생성: (" << x << ", " << y << ")" << endl;
    }
    
    ~Point() {
        cout << "Point 소멸: (" << x << ", " << y << ")" << endl;
    }
    
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    
    // 거리 계산
    double distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }
};

// 여러 생성자 오버로딩
class BankAccount {
private:
    string owner;
    int accountNumber;
    double balance;

public:
    // 생성자 1: 모든 정보 제공
    BankAccount(string own, int accNum, double bal) 
        : owner(own), accountNumber(accNum), balance(bal) {
        cout << "계좌 개설: " << owner << endl;
    }
    
    // 생성자 2: 초기 잔액 없음
    BankAccount(string own, int accNum) 
        : owner(own), accountNumber(accNum), balance(0.0) {
        cout << "계좌 개설 (초기 잔액 0원): " << owner << endl;
    }
    
    // 소멸자
    ~BankAccount() {
        cout << "계좌 해지: " << owner << " (잔액: " << balance << "원)" << endl;
    }
    
    void deposit(double amount) {
        balance += amount;
        cout << amount << "원 입금 완료. 잔액: " << balance << "원" << endl;
    }
    
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << amount << "원 출금 완료. 잔액: " << balance << "원" << endl;
        } else {
            cout << "잔액 부족!" << endl;
        }
    }
    
    void printInfo() {
        cout << "소유자: " << owner << ", 계좌번호: " << accountNumber 
             << ", 잔액: " << balance << "원" << endl;
    }
};

int main() {
    cout << "=== Student 클래스 ===" << endl;
    Student s1;  // 기본 생성자
    s1.printInfo();
    
    Student s2("홍길동", 2024001, 3.8);  // 매개변수 생성자
    s2.printInfo();
    
    cout << "\n=== Point 클래스 ===" << endl;
    {
        Point p1;
        Point p2(3, 4);
        p2.print();
        cout << "원점으로부터의 거리: " << p2.distanceFromOrigin() << endl;
    }  // 블록을 벗어나면 소멸자 호출
    
    cout << "\n=== BankAccount 클래스 ===" << endl;
    {
        BankAccount acc1("김철수", 12345, 100000);
        acc1.printInfo();
        acc1.deposit(50000);
        acc1.withdraw(30000);
        
        cout << endl;
        
        BankAccount acc2("이영희", 67890);
        acc2.printInfo();
        acc2.deposit(200000);
        acc2.withdraw(50000);
    }  // 소멸자 자동 호출
    
    cout << "\n프로그램 종료" << endl;
    
    return 0;
}

