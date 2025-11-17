#include <iostream>
#include <cstring>

using namespace std;

// 배열을 매개변수로 받는 함수
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 배열을 수정하는 함수
void modifyArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// 배열의 합을 구하는 함수
int sumArray(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 배열에서 최댓값을 찾는 함수
int findMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    // 배열과 포인터의 관계
    cout << "=== 배열과 포인터 ===" << endl;
    int numbers[] = {1, 2, 3, 4, 5};
    int* ptr = numbers;
    
    cout << "배열 접근 방법:" << endl;
    cout << "numbers[0] = " << numbers[0] << endl;
    cout << "*numbers = " << *numbers << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "ptr[0] = " << ptr[0] << endl;
    
    // 함수에 배열 전달
    cout << "\n=== 함수에 배열 전달 ===" << endl;
    int data[] = {10, 20, 30, 40, 50};
    int size = sizeof(data) / sizeof(data[0]);
    
    cout << "원본 배열: ";
    printArray(data, size);
    
    modifyArray(data, size);
    cout << "2배 후 배열: ";
    printArray(data, size);
    
    // 배열 함수 활용
    cout << "\n=== 배열 함수 활용 ===" << endl;
    int values[] = {23, 67, 12, 89, 45, 34};
    int len = sizeof(values) / sizeof(values[0]);
    
    cout << "배열: ";
    printArray(values, len);
    cout << "합계: " << sumArray(values, len) << endl;
    cout << "최댓값: " << findMax(values, len) << endl;
    
    // 포인터 산술 연산
    cout << "\n=== 포인터 산술 연산 ===" << endl;
    int arr[] = {100, 200, 300, 400, 500};
    int* p = arr;
    
    cout << "포인터를 이용한 순회:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "*(p + " << i << ") = " << *(p + i) << endl;
    }
    
    // C 스타일 문자열
    cout << "\n=== C 스타일 문자열 ===" << endl;
    char str1[] = "Hello";
    char* str2 = (char*)"World";
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    
    // 문자열 길이
    cout << "str1 길이: " << strlen(str1) << endl;
    
    // 문자열 복사
    char dest[20];
    strcpy(dest, str1);
    cout << "복사된 문자열: " << dest << endl;
    
    // 문자열 연결
    strcat(dest, " ");
    strcat(dest, str2);
    cout << "연결된 문자열: " << dest << endl;
    
    // 동적 배열과 포인터
    cout << "\n=== 동적 배열과 포인터 ===" << endl;
    int n = 5;
    int* dynamicArr = new int[n];
    
    // 초기화
    for (int i = 0; i < n; i++) {
        dynamicArr[i] = (i + 1) * 10;
    }
    
    cout << "동적 배열: ";
    printArray(dynamicArr, n);
    
    // 재할당 (크기 변경)
    int newSize = 8;
    int* newArr = new int[newSize];
    
    // 기존 데이터 복사
    for (int i = 0; i < n; i++) {
        newArr[i] = dynamicArr[i];
    }
    
    // 새로운 데이터 추가
    for (int i = n; i < newSize; i++) {
        newArr[i] = (i + 1) * 10;
    }
    
    delete[] dynamicArr;
    dynamicArr = newArr;
    
    cout << "확장된 배열: ";
    printArray(dynamicArr, newSize);
    
    delete[] dynamicArr;
    
    return 0;
}

