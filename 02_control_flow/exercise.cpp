/*
연습 문제

문제 1: 점수를 입력받아 학점을 출력하는 프로그램
        90-100: A, 80-89: B, 70-79: C, 60-69: D, 0-59: F

문제 2: 1부터 100까지의 합을 구하는 프로그램

문제 3: 구구단 전체를 출력하는 프로그램 (2단~9단)

문제 4: 숫자를 입력받아 소수(prime number)인지 판별하는 프로그램

문제 5: 다음과 같은 별 패턴을 출력하는 프로그램
    *
   ***
  *****
 *******
*********
*/

#include <iostream>

using namespace std;


void Problem1() {
    cout << "점수를 입력하세요 :";
    int score;
    cin >> score;

    if(score>= 90) {
        cout << "A" << endl;
    } else if(score >= 80) {
        cout << "B" << endl;
    } else if(score >= 70) {
        cout << "C" << endl;
    } else if(score >= 60) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }
}

void Problem2() {
    cout << "1부터 100까지의 합 : " << (100 * (100 + 1) / 2) << endl;
}

void Problem3() {
    for(int i = 2; i <= 9; i++) {
        cout << "[" << i << "단]" << endl;
        for(int j = 1; j <= 9; j++) {
            cout << i << " x " << j << " = " << (i * j) << endl;
        }
    }
}

void Problem4() {
    cout << "숫자를 입력하세요 :";
    int num;
    cin >> num;
    if(num <= 1) {
        cout << num << "은(는) 소수가 아닙니다." << endl;
    } else {
        for(int i = 2; i <= num; i++) {
            if(num % i == 0) {
                cout << "소수가 아닙니다." << endl;
                break;
            }
        }
    }
}

void Problem5() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5 - i; j++) {
            cout << " ";
        }
        for(int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {

    Problem1();
    Problem2();
    Problem3();
    Problem4();
    Problem5();
    
    return 0;
}
