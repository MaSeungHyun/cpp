#include <iostream>

using namespace std;

int main() {
    // 포인터 기초
    cout << "=== 포인터 기초 ===" << endl;
    int num = 10;
    int* ptr = &num;  // num의 주소를 ptr에 저장
    
    cout << "num의 값: " << num << endl;
    cout << "num의 주소: " << &num << endl;
    cout << "ptr의 값 (주소): " << ptr << endl;
    cout << "*ptr의 값 (역참조): " << *ptr << endl;
    
    // 포인터를 통한 값 변경
    cout << "\n=== 포인터를 통한 값 변경 ===" << endl;
    *ptr = 20;
    cout << "num의 새로운 값: " << num << endl;
    
    // 여러 포인터
    cout << "\n=== 여러 포인터 ===" << endl;
    int a = 5;
    int* p1 = &a;
    int* p2 = &a;
    
    cout << "a = " << a << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    
    *p1 = 10;
    cout << "p1을 통해 변경 후:" << endl;
    cout << "a = " << a << endl;
    cout << "*p2 = " << *p2 << endl;
    
    // NULL 포인터
    cout << "\n=== NULL 포인터 ===" << endl;
    int* nullPtr = nullptr;
    cout << "nullPtr = " << nullPtr << endl;
    
    // 포인터 연산
    cout << "\n=== 포인터 연산 ===" << endl;
    int arr[] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;  // 배열의 첫 번째 요소를 가리킴
    
    cout << "첫 번째 요소: " << *arrPtr << endl;
    cout << "두 번째 요소: " << *(arrPtr + 1) << endl;
    cout << "세 번째 요소: " << *(arrPtr + 2) << endl;
    
    // 포인터 증가
    cout << "\n=== 포인터 증가 ===" << endl;
    int* p = arr;
    for (int i = 0; i < 5; i++) {
        cout << "*p = " << *p << endl;
        p++;
    }
    
    // 포인터와 배열
    cout << "\n=== 포인터와 배열 ===" << endl;
    int data[] = {100, 200, 300};
    cout << "배열 이름으로 접근:" << endl;
    cout << "data[0] = " << data[0] << endl;
    cout << "data[1] = " << data[1] << endl;
    
    cout << "포인터로 접근:" << endl;
    cout << "*data = " << *data << endl;
    cout << "*(data + 1) = " << *(data + 1) << endl;
    
    // 포인터의 포인터
    cout << "\n=== 포인터의 포인터 ===" << endl;
    int value = 42;
    int* ptr1 = &value;
    int** ptr2 = &ptr1;
    
    cout << "value = " << value << endl;
    cout << "*ptr1 = " << *ptr1 << endl;
    cout << "**ptr2 = " << **ptr2 << endl;
    
    // const 포인터
    cout << "\n=== const 포인터 ===" << endl;
    int x = 10;
    const int* constPtr = &x;  // 포인터가 가리키는 값을 변경할 수 없음
    cout << "*constPtr = " << *constPtr << endl;
    // *constPtr = 20;  // 오류!
    x = 20;  // 직접 변경은 가능
    cout << "*constPtr = " << *constPtr << endl;
    
    return 0;
}

