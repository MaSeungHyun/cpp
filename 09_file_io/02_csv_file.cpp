#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    int id;
    double gpa;
};

// CSV 파일에 학생 정보 저장
void saveStudents(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return;
    }
    
    // 헤더 쓰기
    file << "Name,ID,GPA" << endl;
    
    // 데이터 쓰기
    for (const auto& student : students) {
        file << student.name << "," << student.id << "," << student.gpa << endl;
    }
    
    file.close();
    cout << "파일 저장 완료: " << filename << endl;
}

// CSV 파일에서 학생 정보 읽기
vector<Student> loadStudents(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다." << endl;
        return students;
    }
    
    string line;
    getline(file, line);  // 헤더 건너뛰기
    
    while (getline(file, line)) {
        stringstream ss(line);
        Student student;
        string token;
        
        getline(ss, student.name, ',');
        getline(ss, token, ',');
        student.id = stoi(token);
        getline(ss, token, ',');
        student.gpa = stod(token);
        
        students.push_back(student);
    }
    
    file.close();
    cout << "파일 로드 완료: " << filename << endl;
    return students;
}

int main() {
    // 학생 데이터 생성
    vector<Student> students = {
        {"홍길동", 2024001, 3.8},
        {"김철수", 2024002, 3.5},
        {"이영희", 2024003, 4.0},
        {"박민수", 2024004, 3.7}
    };
    
    // CSV 파일에 저장
    cout << "=== CSV 파일 저장 ===" << endl;
    saveStudents(students, "students.csv");
    
    // CSV 파일에서 로드
    cout << "\n=== CSV 파일 로드 ===" << endl;
    vector<Student> loadedStudents = loadStudents("students.csv");
    
    cout << "\n불러온 학생 정보:" << endl;
    cout << "----------------------------------------" << endl;
    for (const auto& student : loadedStudents) {
        cout << "이름: " << student.name 
             << ", ID: " << student.id 
             << ", GPA: " << student.gpa << endl;
    }
    
    // 통계 계산
    double totalGPA = 0;
    for (const auto& student : loadedStudents) {
        totalGPA += student.gpa;
    }
    cout << "----------------------------------------" << endl;
    cout << "평균 GPA: " << (totalGPA / loadedStudents.size()) << endl;
    
    return 0;
}

