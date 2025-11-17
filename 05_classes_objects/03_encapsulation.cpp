#include <iostream>
#include <string>

using namespace std;

// 캡슐화: 데이터 은닉과 접근 제어
class BankAccount {
private:
    // private 멤버: 클래스 외부에서 접근 불가
    string owner;
    int accountNumber;
    double balance;
    string password;

public:
    // 생성자
    BankAccount(string own, int accNum, string pwd) 
        : owner(own), accountNumber(accNum), balance(0.0), password(pwd) {
        cout << "계좌 개설: " << owner << endl;
    }
    
    // Getter 함수들 (읽기 전용)
    string getOwner() const {
        return owner;
    }
    
    int getAccountNumber() const {
        return accountNumber;
    }
    
    double getBalance() const {
        return balance;
    }
    
    // Setter 함수들 (유효성 검사 포함)
    bool changePassword(string oldPwd, string newPwd) {
        if (oldPwd == password) {
            password = newPwd;
            cout << "비밀번호가 변경되었습니다." << endl;
            return true;
        }
        cout << "비밀번호가 일치하지 않습니다." << endl;
        return false;
    }
    
    // 입금 (양수만 가능)
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << "원 입금 완료. 잔액: " << balance << "원" << endl;
            return true;
        }
        cout << "입금액은 양수여야 합니다." << endl;
        return false;
    }
    
    // 출금 (비밀번호와 잔액 확인)
    bool withdraw(double amount, string pwd) {
        if (pwd != password) {
            cout << "비밀번호가 일치하지 않습니다." << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "출금액은 양수여야 합니다." << endl;
            return false;
        }
        if (balance < amount) {
            cout << "잔액이 부족합니다." << endl;
            return false;
        }
        balance -= amount;
        cout << amount << "원 출금 완료. 잔액: " << balance << "원" << endl;
        return true;
    }
    
    void printInfo() const {
        cout << "소유자: " << owner << ", 계좌번호: " << accountNumber 
             << ", 잔액: " << balance << "원" << endl;
    }
};

// 학생 클래스 - 데이터 유효성 검사
class Student {
private:
    string name;
    int age;
    double gpa;

public:
    Student(string n, int a, double g) : name(n) {
        setAge(a);
        setGPA(g);
    }
    
    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    double getGPA() const { return gpa; }
    
    // Setters with validation
    void setName(string n) {
        if (!n.empty()) {
            name = n;
        }
    }
    
    void setAge(int a) {
        if (a >= 0 && a <= 150) {
            age = a;
        } else {
            age = 0;
            cout << "유효하지 않은 나이입니다. 0으로 설정합니다." << endl;
        }
    }
    
    void setGPA(double g) {
        if (g >= 0.0 && g <= 4.5) {
            gpa = g;
        } else {
            gpa = 0.0;
            cout << "유효하지 않은 GPA입니다. 0.0으로 설정합니다." << endl;
        }
    }
    
    void printInfo() const {
        cout << "이름: " << name << ", 나이: " << age << ", GPA: " << gpa << endl;
    }
};

// 온도 클래스 - 읽기 전용 속성
class Temperature {
private:
    double celsius;

public:
    Temperature(double c) : celsius(c) {}
    
    // Getter
    double getCelsius() const {
        return celsius;
    }
    
    // Setter with validation
    void setCelsius(double c) {
        if (c >= -273.15) {  // 절대영도 이상
            celsius = c;
        } else {
            cout << "온도는 -273.15°C 이상이어야 합니다." << endl;
        }
    }
    
    // 다른 단위로 변환 (읽기 전용)
    double toFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32;
    }
    
    double toKelvin() const {
        return celsius + 273.15;
    }
    
    void printAll() const {
        cout << "섭씨: " << celsius << "°C" << endl;
        cout << "화씨: " << toFahrenheit() << "°F" << endl;
        cout << "켈빈: " << toKelvin() << "K" << endl;
    }
};

int main() {
    cout << "=== BankAccount 클래스 ===" << endl;
    BankAccount acc("홍길동", 12345, "1234");
    acc.printInfo();
    
    acc.deposit(100000);
    acc.withdraw(30000, "1234");  // 올바른 비밀번호
    acc.withdraw(30000, "0000");  // 잘못된 비밀번호
    acc.deposit(-5000);  // 음수 입금 시도
    
    acc.changePassword("1234", "5678");
    acc.withdraw(20000, "5678");  // 새 비밀번호
    
    // acc.balance = 1000000;  // 오류! private 멤버 접근 불가
    
    cout << "\n=== Student 클래스 ===" << endl;
    Student student("김철수", 20, 3.8);
    student.printInfo();
    
    student.setAge(21);
    student.setGPA(4.0);
    student.printInfo();
    
    student.setAge(200);  // 유효하지 않은 값
    student.setGPA(5.0);  // 유효하지 않은 값
    student.printInfo();
    
    cout << "\n=== Temperature 클래스 ===" << endl;
    Temperature temp(25.0);
    temp.printAll();
    
    cout << endl;
    temp.setCelsius(100.0);
    temp.printAll();
    
    cout << endl;
    temp.setCelsius(-300.0);  // 유효하지 않은 값
    
    return 0;
}

