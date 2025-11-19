/*
연습 문제

문제 1: 배열에서 최댓값과 최솟값을 찾고, 그 위치(인덱스)를 출력하는 프로그램

문제 2: 2차원 배열로 두 행렬의 곱셈을 구현하는 프로그램
        (3x2 행렬과 2x3 행렬의 곱셈)

문제 3: 동적 배열을 사용하여 사용자가 입력한 개수만큼의 학생 점수를 관리하는 프로그램
        - 평균, 최고점, 최저점 계산
        - 평균 이상인 학생 수 출력

문제 4: 포인터를 이용하여 문자열을 뒤집는 함수 작성
        (in-place 방식으로 구현)

문제 5: 동적 2차원 배열을 사용하여 파스칼의 삼각형 출력
*/

#include <iostream>

using namespace std;


int findMax(int* arr, int size) {
        int max = arr[0];
        int min = arr[0];
        for(int i = 1; i < size; i++) {
            if(*(arr + i) > max) {
                max = *(arr + i);
            } 
        }
        return max;
}

int findMin(int* arr, int size) {
        int min = arr[0];
        for(int i = 1; i < size; i++) {
            if(*(arr + i) < min) {
                min = *(arr + i);
            }
        }
        return min;
}

void printMaxAndMin(int max, int min) {
    cout << "최댓값: " << max << endl;
    cout << "최솟값: " << min << endl;
}

int problem1() {
      cout << "배열의 크기를 입력하세요: ";
      int size;
      cin >> size;

      int* arr = new int[size];
      cout << "배열을 입력하세요" << endl;

      for(int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
      }

      int max = findMax(arr, size);
      int min = findMin(arr, size);
      printMaxAndMin(max, min);
      delete[] arr;

      return 0;
}

int problem2() {
    int matrix1[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int matrix2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int result[3][3] = {{0},{0},{0}};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    cout << "결과: " << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int average(int* scores, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += scores[i];
    }
 
    return sum / size;
}

int aboveAverage(int* scores, int size) {
    int avg = average(scores, size);
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(scores[i] > avg) {
            count++;
        }
    }
    return count;
}

void problem3() {
    cout << "학생 수를 입력하세요: ";
    int size;
    cin >> size;

    int* scores = new int[size];
    cout << "학생 점수를 입력하세요: ";
    for(int i = 0; i < size; i++) {
        cin >> scores[i];
    }

    int max = findMax(scores, size);
    int min = findMin(scores, size);
    int avg = average(scores, size);
    int aboveAverageCount = aboveAverage(scores, size);
    cout << "최고점: " << max << endl;
    cout << "최저점: " << min << endl;
    cout << "평균: " << avg << endl;
    cout << "평균 이상인 학생 수: " << aboveAverageCount << endl;
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
    cin >> str;
    reverse(str);
    cout << "뒤집힌 문자열: " << str << endl;
}

void problem5() {
    cout << "파스칼의 삼각형 크기를 입력하세요: ";
    int size;
    cin >> size;
    int** triangle = new int*[size];
    for(int i = 0; i < size; i++) {
        triangle[i] = new int[i + 1];
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i + 1; j++) {
            if(j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i + 1; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < size; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
}




int main() {
    // 여기에 코드를 작성하세요
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();

    return 0;
}
