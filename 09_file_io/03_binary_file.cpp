#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Person {
    char name[50];
    int age;
    double height;
};

int main() {
    // 바이너리 파일 쓰기
    cout << "=== 바이너리 파일 쓰기 ===" << endl;
    
    Person people[3];
    strcpy(people[0].name, "홍길동");
    people[0].age = 25;
    people[0].height = 175.5;
    
    strcpy(people[1].name, "김철수");
    people[1].age = 30;
    people[1].height = 180.0;
    
    strcpy(people[2].name, "이영희");
    people[2].age = 28;
    people[2].height = 165.5;
    
    ofstream outFile("people.dat", ios::binary);
    if (outFile.is_open()) {
        outFile.write((char*)people, sizeof(Person) * 3);
        outFile.close();
        cout << "바이너리 파일 저장 완료" << endl;
    }
    
    // 바이너리 파일 읽기
    cout << "\n=== 바이너리 파일 읽기 ===" << endl;
    
    Person loadedPeople[3];
    ifstream inFile("people.dat", ios::binary);
    if (inFile.is_open()) {
        inFile.read((char*)loadedPeople, sizeof(Person) * 3);
        inFile.close();
        
        cout << "불러온 데이터:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "이름: " << loadedPeople[i].name 
                 << ", 나이: " << loadedPeople[i].age 
                 << ", 키: " << loadedPeople[i].height << "cm" << endl;
        }
    }
    
    return 0;
}

