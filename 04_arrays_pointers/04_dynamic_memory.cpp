#include <iostream>

using namespace std;

int main() {
    // 동적 메모리 할당 (단일 변수)
    cout << "=== 동적 메모리 할당 (변수) ===" << endl;
    int* ptr = new int;
    *ptr = 42;
    cout << "*ptr = " << *ptr << endl;
    delete ptr;  // 메모리 해제
    
    // 동적 배열
    cout << "\n=== 동적 배열 ===" << endl;
    int size;
    cout << "배열 크기를 입력하세요: ";
    cin >> size;
    
    int* arr = new int[size];
    
    // 배열 초기화
    cout << "배열 요소를 입력하세요:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    
    // 배열 출력
    cout << "\n입력한 배열:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 합계와 평균
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    double average = (double)sum / size;
    cout << "합계: " << sum << endl;
    cout << "평균: " << average << endl;
    
    delete[] arr;  // 동적 배열 메모리 해제
    
    // 동적 2차원 배열
    cout << "\n=== 동적 2차원 배열 ===" << endl;
    int rows = 3, cols = 4;
    
    // 2차원 배열 할당
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    // 초기화
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = count++;
        }
    }
    
    // 출력
    cout << "행렬:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // 2차원 배열 메모리 해제
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    // 실용적인 예제: 학생 점수 관리
    cout << "\n=== 학생 점수 관리 ===" << endl;
    int numStudents;
    cout << "학생 수를 입력하세요: ";
    cin >> numStudents;
    
    // 점수 배열 동적 할당
    double* scores = new double[numStudents];
    
    // 점수 입력
    for (int i = 0; i < numStudents; i++) {
        cout << "학생 " << (i + 1) << "의 점수: ";
        cin >> scores[i];
    }
    
    // 최고점, 최저점, 평균 계산
    double maxScore = scores[0];
    double minScore = scores[0];
    double totalSum = 0;
    
    for (int i = 0; i < numStudents; i++) {
        if (scores[i] > maxScore) maxScore = scores[i];
        if (scores[i] < minScore) minScore = scores[i];
        totalSum += scores[i];
    }
    
    cout << "\n=== 결과 ===" << endl;
    cout << "최고점: " << maxScore << endl;
    cout << "최저점: " << minScore << endl;
    cout << "평균: " << (totalSum / numStudents) << endl;
    
    delete[] scores;  // 메모리 해제
    
    cout << "\n모든 동적 메모리가 해제되었습니다." << endl;
    
    return 0;
}

