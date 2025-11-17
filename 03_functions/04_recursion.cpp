#include <iostream>

using namespace std;

// 재귀 함수 (Recursive Function)

// 팩토리얼 계산
// n! = n × (n-1) × (n-2) × ... × 1
int factorial(int n) {
    // 기저 조건 (base case)
    if (n <= 1) {
        return 1;
    }
    // 재귀 호출
    return n * factorial(n - 1);
}

// 피보나치 수열
// F(n) = F(n-1) + F(n-2)
// F(0) = 0, F(1) = 1
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 1부터 n까지의 합
int sum(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sum(n - 1);
}

// 거듭제곱 계산
// power(base, exp) = base^exp
int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp - 1);
}

// 최대공약수 (유클리드 호제법)
// gcd(a, b) = gcd(b, a % b)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 숫자의 각 자릿수 합
int digitSum(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + digitSum(n / 10);
}

int main() {
    cout << "=== 팩토리얼 ===" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << "! = " << factorial(i) << endl;
    }
    
    cout << "\n=== 피보나치 수열 ===" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "F(" << i << ") = " << fibonacci(i) << endl;
    }
    
    cout << "\n=== 1부터 n까지의 합 ===" << endl;
    cout << "1 + 2 + ... + 100 = " << sum(100) << endl;
    
    cout << "\n=== 거듭제곱 ===" << endl;
    cout << "2^5 = " << power(2, 5) << endl;
    cout << "3^4 = " << power(3, 4) << endl;
    
    cout << "\n=== 최대공약수 ===" << endl;
    cout << "gcd(48, 18) = " << gcd(48, 18) << endl;
    cout << "gcd(100, 35) = " << gcd(100, 35) << endl;
    
    cout << "\n=== 자릿수 합 ===" << endl;
    cout << "digitSum(12345) = " << digitSum(12345) << endl;
    cout << "digitSum(9999) = " << digitSum(9999) << endl;
    
    return 0;
}

