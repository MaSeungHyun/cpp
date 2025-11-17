#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 함수 객체
struct IsEven {
    bool operator()(int n) const {
        return n % 2 == 0;
    }
};

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // sort
    cout << "=== 정렬 ===" << endl;
    cout << "원본: ";
    for (int n : v) cout << n << " ";
    cout << endl;
    
    sort(v.begin(), v.end());
    cout << "오름차순: ";
    for (int n : v) cout << n << " ";
    cout << endl;
    
    // find
    cout << "\n=== 검색 ===" << endl;
    auto it = find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        cout << "5를 찾았습니다. 위치: " << (it - v.begin()) << endl;
    }
    
    // count
    int count_3 = count(v.begin(), v.end(), 3);
    cout << "3의 개수: " << count_3 << endl;
    
    // count_if (조건에 맞는 개수)
    int evenCount = count_if(v.begin(), v.end(), IsEven());
    cout << "짝수 개수: " << evenCount << endl;
    
    // accumulate (합계)
    cout << "\n=== 합계와 통계 ===" << endl;
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "합계: " << sum << endl;
    cout << "평균: " << (sum / (double)v.size()) << endl;
    
    // min_element, max_element
    auto minIt = min_element(v.begin(), v.end());
    auto maxIt = max_element(v.begin(), v.end());
    cout << "최솟값: " << *minIt << endl;
    cout << "최댓값: " << *maxIt << endl;
    
    // reverse
    cout << "\n=== 역순 ===" << endl;
    reverse(v.begin(), v.end());
    cout << "역순: ";
    for (int n : v) cout << n << " ";
    cout << endl;
    
    // unique (연속된 중복 제거)
    cout << "\n=== 중복 제거 ===" << endl;
    vector<int> v2 = {1, 1, 2, 2, 3, 3, 3, 4, 5, 5};
    auto last = unique(v2.begin(), v2.end());
    v2.erase(last, v2.end());
    cout << "중복 제거: ";
    for (int n : v2) cout << n << " ";
    cout << endl;
    
    // transform (변환)
    cout << "\n=== 변환 ===" << endl;
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> v4(v3.size());
    transform(v3.begin(), v3.end(), v4.begin(), [](int n) {
        return n * n;
    });
    cout << "제곱: ";
    for (int n : v4) cout << n << " ";
    cout << endl;
    
    // for_each
    cout << "\n=== for_each ===" << endl;
    for_each(v3.begin(), v3.end(), [](int n) {
        cout << n * 10 << " ";
    });
    cout << endl;
    
    // binary_search (이진 검색 - 정렬된 컨테이너)
    cout << "\n=== 이진 검색 ===" << endl;
    vector<int> v5 = {1, 3, 5, 7, 9};
    bool found = binary_search(v5.begin(), v5.end(), 5);
    cout << "5 존재? " << (found ? "예" : "아니오") << endl;
    
    return 0;
}

