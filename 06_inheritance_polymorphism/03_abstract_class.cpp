#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 추상 클래스 (순수 가상 함수 포함)
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) : name(n), id(i) {}
    
    virtual ~Employee() {}
    
    // 순수 가상 함수 (= 0)
    virtual double calculateSalary() const = 0;
    virtual void printInfo() const = 0;
    
    string getName() const { return name; }
    int getID() const { return id; }
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(string n, int i, double salary) 
        : Employee(n, i), monthlySalary(salary) {}
    
    double calculateSalary() const override {
        return monthlySalary;
    }
    
    void printInfo() const override {
        cout << "[정규직] " << name << " (ID: " << id << ")" << endl;
        cout << "월급: " << calculateSalary() << "원" << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTimeEmployee(string n, int i, double rate, int hours) 
        : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}
    
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
    
    void printInfo() const override {
        cout << "[파트타임] " << name << " (ID: " << id << ")" << endl;
        cout << "시급: " << hourlyRate << "원, 근무시간: " << hoursWorked << "시간" << endl;
        cout << "총 급여: " << calculateSalary() << "원" << endl;
    }
};

// 인터페이스 역할을 하는 추상 클래스
class Drawable {
public:
    virtual ~Drawable() {}
    virtual void draw() const = 0;
};

class Movable {
public:
    virtual ~Movable() {}
    virtual void move(int dx, int dy) = 0;
};

// 다중 상속
class GameObject : public Drawable, public Movable {
protected:
    int x, y;
    string name;

public:
    GameObject(string n, int x_pos, int y_pos) 
        : name(n), x(x_pos), y(y_pos) {}
    
    virtual ~GameObject() {}
    
    void draw() const override {
        cout << name << " 위치: (" << x << ", " << y << ")" << endl;
    }
    
    void move(int dx, int dy) override {
        x += dx;
        y += dy;
        cout << name << " 이동: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    cout << "=== 추상 클래스 예제 ===" << endl;
    
    // Employee emp("김철수", 1001);  // 오류! 추상 클래스는 인스턴스화 불가
    
    vector<Employee*> employees;
    employees.push_back(new FullTimeEmployee("홍길동", 1001, 3000000));
    employees.push_back(new PartTimeEmployee("김철수", 1002, 15000, 120));
    employees.push_back(new FullTimeEmployee("이영희", 1003, 3500000));
    employees.push_back(new PartTimeEmployee("박민수", 1004, 12000, 80));
    
    cout << "전체 직원 정보:" << endl;
    double totalSalary = 0;
    for (const auto& emp : employees) {
        emp->printInfo();
        totalSalary += emp->calculateSalary();
        cout << endl;
    }
    
    cout << "총 급여: " << totalSalary << "원" << endl;
    
    // 메모리 해제
    for (auto emp : employees) {
        delete emp;
    }
    
    cout << "\n=== 다중 상속 예제 ===" << endl;
    GameObject player("플레이어", 0, 0);
    GameObject enemy("적", 10, 5);
    
    player.draw();
    player.move(5, 3);
    player.draw();
    
    cout << endl;
    
    enemy.draw();
    enemy.move(-2, 1);
    enemy.draw();
    
    return 0;
}

