/*
연습 문제

문제 1: 두 수의 최대공약수(GCD)를 구하는 함수 작성
        (유클리드 호제법 사용)

문제 2: 팩토리얼을 구하는 재귀 함수와 반복문 함수를 각각 작성하고 비교

문제 3: 정수 배열을 받아 평균을 계산하는 함수 작성

문제 4: 문자열을 뒤집는 함수 작성 (참조 사용)

문제 5: 소수(prime number)를 판별하는 함수 작성
*/


#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
void problem1() {
    cout << "두 수를 입력하세요: ";
    int num1, num2;
    cin >> num1 >> num2;
    cout << "최대공약수: " << gcd(num1, num2) << endl;
}

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int factorial_iterative(int n) {
    int result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void problem2() {
    cout << "숫자를 입력하세요: ";
    int num;
    cin >> num;
    cout << "팩토리얼: " << factorial(num) << endl;
    cout << "반복문 팩토리얼: " << factorial_iterative(num) << endl;
}

int average(int* arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

void problem3() {
    cout << "배열의 크기를 입력하세요: ";
    int size;
    cin >> size;
    int* arr = new int[size];
    cout << "배열을 입력하세요: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "평균: " << average(arr, size) << endl;
    delete[] arr;
}

void reverse(string& str) {
    int left = 0;
    int right = str.size() - 1;
    while(left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}
void problem4() {
    cout << "문자열을 입력하세요: ";
    string str;
    cin.ignore();
    getline(cin, str);
    reverse(str);
    cout << "뒤집힌 문자열: " << str << endl;
}



bool isPrime(int num) {
    if(num <= 1) {
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void problem5() {
    cout << "숫자를 입력하세요: ";
    int num;
    cin >> num;
    if(isPrime(num)) {
        cout << num << "은(는) 소수입니다." << endl;
    } else {
        cout << num << "은(는) 소수가 아닙니다." << endl;
    }
}

int main() {
    
    
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();

    return 0;
}

