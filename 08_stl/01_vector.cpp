#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // vector 기본
    cout << "=== vector 기본 ===" << endl;
    vector<int> v1;
    
    // 요소 추가
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    
    cout << "v1: ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    
    // 초기화
    vector<int> v2 = {1, 2, 3, 4, 5};
    vector<int> v3(5, 100);  // 100이 5개
    
    // 범위 기반 for 루프
    cout << "v2: ";
    for (int num : v2) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "v3: ";
    for (int num : v3) {
        cout << num << " ";
    }
    cout << endl;
    
    // 메서드
    cout << "\n=== vector 메서드 ===" << endl;
    vector<int> v = {5, 2, 8, 1, 9};
    
    cout << "크기: " << v.size() << endl;
    cout << "첫 번째 요소: " << v.front() << endl;
    cout << "마지막 요소: " << v.back() << endl;
    cout << "비었는가? " << (v.empty() ? "예" : "아니오") << endl;
    
    v.pop_back();  // 마지막 요소 제거
    cout << "pop_back 후: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    
    // 정렬
    cout << "\n=== 정렬 ===" << endl;
    sort(v.begin(), v.end());
    cout << "오름차순: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    
    sort(v.begin(), v.end(), greater<int>());
    cout << "내림차순: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    
    // 삽입과 삭제
    cout << "\n=== 삽입과 삭제 ===" << endl;
    v.insert(v.begin() + 2, 100);  // 인덱스 2에 100 삽입
    cout << "삽입 후: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    
    v.erase(v.begin() + 1);  // 인덱스 1 삭제
    cout << "삭제 후: ";
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
    
    // 검색
    cout << "\n=== 검색 ===" << endl;
    auto it = find(v.begin(), v.end(), 100);
    if (it != v.end()) {
        cout << "100을 찾았습니다. 인덱스: " << (it - v.begin()) << endl;
    }
    
    int count_5 = count(v.begin(), v.end(), 5);
    cout << "5의 개수: " << count_5 << endl;
    
    // 2차원 vector
    cout << "\n=== 2차원 vector ===" << endl;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

