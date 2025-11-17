#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    // map 기본
    cout << "=== map 기본 ===" << endl;
    map<string, int> ages;
    
    // 요소 추가
    ages["홍길동"] = 25;
    ages["김철수"] = 30;
    ages["이영희"] = 28;
    
    // 출력
    for (const auto& pair : ages) {
        cout << pair.first << ": " << pair.second << "살" << endl;
    }
    
    // 검색
    cout << "\n=== map 검색 ===" << endl;
    string name = "김철수";
    if (ages.find(name) != ages.end()) {
        cout << name << "의 나이: " << ages[name] << "살" << endl;
    }
    
    // count (존재 여부 확인)
    if (ages.count("박민수") == 0) {
        cout << "박민수는 없습니다." << endl;
    }
    
    // 단어 빈도 계산
    cout << "\n=== 단어 빈도 ===" << endl;
    string text = "apple banana apple orange banana apple";
    map<string, int> wordCount;
    
    string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                wordCount[word]++;
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        wordCount[word]++;
    }
    
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << "번" << endl;
    }
    
    // set 기본
    cout << "\n=== set 기본 ===" << endl;
    set<int> numbers = {5, 2, 8, 2, 1, 9, 5};  // 중복 자동 제거, 자동 정렬
    
    cout << "set: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // 삽입
    numbers.insert(3);
    numbers.insert(7);
    
    cout << "삽입 후: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // 검색
    if (numbers.find(5) != numbers.end()) {
        cout << "5가 존재합니다." << endl;
    }
    
    // 삭제
    numbers.erase(2);
    cout << "삭제 후: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // 학생 점수 관리
    cout << "\n=== 학생 점수 관리 ===" << endl;
    map<string, vector<int>> studentScores;
    
    studentScores["Alice"] = {90, 85, 88};
    studentScores["Bob"] = {78, 92, 85};
    studentScores["Charlie"] = {95, 90, 93};
    
    for (const auto& student : studentScores) {
        cout << student.first << ": ";
        int sum = 0;
        for (int score : student.second) {
            cout << score << " ";
            sum += score;
        }
        double avg = sum / (double)student.second.size();
        cout << "(평균: " << avg << ")" << endl;
    }
    
    return 0;
}

