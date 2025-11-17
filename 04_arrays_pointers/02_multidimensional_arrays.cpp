#include <iostream>

using namespace std;

int main() {
    // 2차원 배열
    cout << "=== 2차원 배열 ===" << endl;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "행렬 출력:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // 성적 관리
    cout << "\n=== 학생 성적 관리 ===" << endl;
    // 3명의 학생, 4과목 점수
    int scores[3][4] = {
        {90, 85, 88, 92},  // 학생 1
        {78, 95, 82, 88},  // 학생 2
        {92, 88, 95, 90}   // 학생 3
    };
    
    string subjects[] = {"국어", "영어", "수학", "과학"};
    
    // 각 학생의 평균 계산
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        cout << "학생 " << (i + 1) << "번: ";
        for (int j = 0; j < 4; j++) {
            sum += scores[i][j];
        }
        double avg = (double)sum / 4;
        cout << "평균 = " << avg << "점" << endl;
    }
    
    // 각 과목의 평균 계산
    cout << "\n과목별 평균:" << endl;
    for (int j = 0; j < 4; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += scores[i][j];
        }
        double avg = (double)sum / 3;
        cout << subjects[j] << ": " << avg << "점" << endl;
    }
    
    // 좌석 배치
    cout << "\n=== 좌석 배치 ===" << endl;
    char seats[5][5];
    
    // 초기화 (빈 좌석: 'O', 예약: 'X')
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            seats[i][j] = 'O';
        }
    }
    
    // 일부 좌석 예약
    seats[0][2] = 'X';
    seats[1][1] = 'X';
    seats[2][3] = 'X';
    
    cout << "현재 좌석 상태:" << endl;
    cout << "  ";
    for (int j = 0; j < 5; j++) {
        cout << (j + 1) << " ";
    }
    cout << endl;
    
    for (int i = 0; i < 5; i++) {
        cout << (char)('A' + i) << " ";
        for (int j = 0; j < 5; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    
    // 행렬 덧셈
    cout << "\n=== 행렬 덧셈 ===" << endl;
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];
    
    // C = A + B
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    cout << "A + B =" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

