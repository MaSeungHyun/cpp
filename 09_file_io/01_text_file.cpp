#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // 파일 쓰기
    cout << "=== 파일 쓰기 ===" << endl;
    ofstream outFile("output.txt");
    
    if (outFile.is_open()) {
        outFile << "안녕하세요!" << endl;
        outFile << "C++ 파일 입출력 예제입니다." << endl;
        outFile << "숫자: " << 42 << endl;
        outFile.close();
        cout << "파일 쓰기 완료: output.txt" << endl;
    } else {
        cout << "파일을 열 수 없습니다." << endl;
    }
    
    // 파일 읽기
    cout << "\n=== 파일 읽기 ===" << endl;
    ifstream inFile("output.txt");
    
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }
    
    // 파일 추가
    cout << "\n=== 파일에 추가 ===" << endl;
    ofstream appendFile("output.txt", ios::app);
    if (appendFile.is_open()) {
        appendFile << "추가된 내용입니다." << endl;
        appendFile.close();
        cout << "내용 추가 완료" << endl;
    }
    
    // 단어 단위로 읽기
    cout << "\n=== 단어 단위 읽기 ===" << endl;
    ofstream wordFile("words.txt");
    wordFile << "apple banana cherry date elderberry";
    wordFile.close();
    
    ifstream wordIn("words.txt");
    string word;
    cout << "단어들: ";
    while (wordIn >> word) {
        cout << word << " ";
    }
    cout << endl;
    wordIn.close();
    
    // 숫자 파일 처리
    cout << "\n=== 숫자 파일 ===" << endl;
    ofstream numFile("numbers.txt");
    for (int i = 1; i <= 10; i++) {
        numFile << i << " ";
    }
    numFile.close();
    
    ifstream numIn("numbers.txt");
    int num;
    int sum = 0;
    cout << "숫자들: ";
    while (numIn >> num) {
        cout << num << " ";
        sum += num;
    }
    cout << "\n합계: " << sum << endl;
    numIn.close();
    
    return 0;
}

