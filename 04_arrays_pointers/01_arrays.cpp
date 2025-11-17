#include <iostream>

using namespace std;

int main() {
    // 배열 선언과 초기화
    cout << "=== 배열 기초 ===" << endl;
    int numbers[5] = {10, 20, 30, 40, 50};
    
    cout << "배열 요소 출력:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }
    
    // 부분 초기화
    cout << "\n=== 부분 초기화 ===" << endl;
    int arr1[5] = {1, 2, 3};  // 나머지는 0으로 초기화
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    // 전체 0으로 초기화
    int arr2[5] = {0};
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    // 크기 자동 결정
    cout << "\n=== 크기 자동 결정 ===" << endl;
    int scores[] = {95, 87, 92, 88, 100};
    int size = sizeof(scores) / sizeof(scores[0]);
    cout << "배열 크기: " << size << endl;
    
    // 배열 값 수정
    cout << "\n=== 배열 값 수정 ===" << endl;
    scores[0] = 90;
    scores[4] = 98;
    for (int i = 0; i < size; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
    
    // 사용자 입력
    cout << "\n=== 사용자 입력 ===" << endl;
    int userArr[3];
    cout << "3개의 정수를 입력하세요: ";
    for (int i = 0; i < 3; i++) {
        cin >> userArr[i];
    }
    
    cout << "입력한 값: ";
    for (int i = 0; i < 3; i++) {
        cout << userArr[i] << " ";
    }
    cout << endl;
    
    // 배열의 합과 평균
    cout << "\n=== 합과 평균 ===" << endl;
    int data[] = {10, 20, 30, 40, 50};
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += data[i];
    }
    double average = (double)sum / 5;
    cout << "합계: " << sum << endl;
    cout << "평균: " << average << endl;
    
    // 최댓값과 최솟값
    cout << "\n=== 최댓값과 최솟값 ===" << endl;
    int values[] = {45, 23, 67, 12, 89, 34};
    int length = sizeof(values) / sizeof(values[0]);
    
    int max = values[0];
    int min = values[0];
    for (int i = 1; i < length; i++) {
        if (values[i] > max) max = values[i];
        if (values[i] < min) min = values[i];
    }
    cout << "최댓값: " << max << endl;
    cout << "최솟값: " << min << endl;
    
    return 0;
}

