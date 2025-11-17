/*
 * 학생 관리 시스템
 * 기능:
 * - 학생 추가
 * - 학생 검색
 * - 학생 목록 보기
 * - 성적순 정렬
 * - 파일 저장/로드
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;
    double gpa;

public:
    Student(string n = "", int i = 0, double g = 0.0) 
        : name(n), id(i), gpa(g) {}
    
    string getName() const { return name; }
    int getID() const { return id; }
    double getGPA() const { return gpa; }
    
    void print() const {
        cout << "ID: " << id 
             << ", 이름: " << name 
             << ", GPA: " << gpa << endl;
    }
    
    // 파일 저장용
    void save(ofstream& file) const {
        file << name << "," << id << "," << gpa << endl;
    }
    
    // 파일 로드용
    static Student load(const string& line) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        
        string name = line.substr(0, pos1);
        int id = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        double gpa = stod(line.substr(pos2 + 1));
        
        return Student(name, id, gpa);
    }
};

class StudentManager {
private:
    vector<Student> students;
    const string filename = "students_data.txt";

public:
    void addStudent() {
        string name;
        int id;
        double gpa;
        
        cout << "\n=== 학생 추가 ===" << endl;
        cout << "이름: ";
        cin.ignore();
        getline(cin, name);
        cout << "학번: ";
        cin >> id;
        cout << "GPA: ";
        cin >> gpa;
        
        students.push_back(Student(name, id, gpa));
        cout << "학생이 추가되었습니다!" << endl;
    }
    
    void searchStudent() {
        int id;
        cout << "\n=== 학생 검색 ===" << endl;
        cout << "학번을 입력하세요: ";
        cin >> id;
        
        for (const auto& student : students) {
            if (student.getID() == id) {
                cout << "학생을 찾았습니다:" << endl;
                student.print();
                return;
            }
        }
        cout << "학생을 찾을 수 없습니다." << endl;
    }
    
    void showAllStudents() {
        cout << "\n=== 전체 학생 목록 ===" << endl;
        if (students.empty()) {
            cout << "등록된 학생이 없습니다." << endl;
            return;
        }
        
        for (const auto& student : students) {
            student.print();
        }
        cout << "총 " << students.size() << "명" << endl;
    }
    
    void sortByGPA() {
        sort(students.begin(), students.end(), 
             [](const Student& a, const Student& b) {
                 return a.getGPA() > b.getGPA();
             });
        cout << "\nGPA순으로 정렬되었습니다." << endl;
    }
    
    void saveToFile() {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "파일을 열 수 없습니다." << endl;
            return;
        }
        
        for (const auto& student : students) {
            student.save(file);
        }
        
        file.close();
        cout << "\n파일에 저장되었습니다: " << filename << endl;
    }
    
    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "파일을 열 수 없습니다." << endl;
            return;
        }
        
        students.clear();
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                students.push_back(Student::load(line));
            }
        }
        
        file.close();
        cout << "\n파일에서 불러왔습니다: " << students.size() << "명" << endl;
    }
};

void showMenu() {
    cout << "\n================================" << endl;
    cout << "    학생 관리 시스템" << endl;
    cout << "================================" << endl;
    cout << "1. 학생 추가" << endl;
    cout << "2. 학생 검색" << endl;
    cout << "3. 전체 학생 보기" << endl;
    cout << "4. GPA순 정렬" << endl;
    cout << "5. 파일에 저장" << endl;
    cout << "6. 파일에서 불러오기" << endl;
    cout << "0. 종료" << endl;
    cout << "================================" << endl;
    cout << "선택: ";
}

int main() {
    StudentManager manager;
    int choice;
    
    cout << "학생 관리 시스템에 오신 것을 환영합니다!" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.searchStudent();
                break;
            case 3:
                manager.showAllStudents();
                break;
            case 4:
                manager.sortByGPA();
                manager.showAllStudents();
                break;
            case 5:
                manager.saveToFile();
                break;
            case 6:
                manager.loadFromFile();
                break;
            case 0:
                cout << "\n프로그램을 종료합니다. 감사합니다!" << endl;
                break;
            default:
                cout << "\n잘못된 선택입니다." << endl;
        }
    } while (choice != 0);
    
    return 0;
}

