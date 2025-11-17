#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    // 기본 람다
    cout << "=== 기본 람다 ===" << endl;
    auto greet = []() {
        cout << "안녕하세요!" << endl;
    };
    greet();
    
    // 매개변수가 있는 람다
    auto add = [](int a, int b) {
        return a + b;
    };
    cout << "add(3, 5) = " << add(3, 5) << endl;
    
    // 캡처
    cout << "\n=== 캡처 ===" << endl;
    int x = 10;
    int y = 20;
    
    // 값으로 캡처
    auto lambda1 = [x, y]() {
        cout << "x + y = " << (x + y) << endl;
    };
    lambda1();
    
    // 참조로 캡처
    auto lambda2 = [&x, &y]() {
        x += 5;
        y += 5;
        cout << "x = " << x << ", y = " << y << endl;
    };
    lambda2();
    cout << "변경 후: x = " << x << ", y = " << y << endl;
    
    // 모든 변수 캡처
    int z = 30;
    auto lambda3 = [=]() {  // 모두 값으로
        cout << "x + y + z = " << (x + y + z) << endl;
    };
    lambda3();
    
    auto lambda4 = [&]() {  // 모두 참조로
        x++; y++; z++;
    };
    lambda4();
    cout << "증가 후: x = " << x << ", y = " << y << ", z = " << z << endl;
    
    // STL과 람다
    cout << "\n=== STL과 람다 ===" << endl;
    vector<int> v = {5, 2, 8, 1, 9, 3, 7};
    
    // 정렬 (내림차순)
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });
    cout << "내림차순: ";
    for (int n : v) cout << n << " ";
    cout << endl;
    
    // 조건에 맞는 개수
    int count = count_if(v.begin(), v.end(), [](int n) {
        return n >= 5;
    });
    cout << "5 이상인 수: " << count << "개" << endl;
    
    // for_each
    cout << "제곱: ";
    for_each(v.begin(), v.end(), [](int n) {
        cout << (n * n) << " ";
    });
    cout << endl;
    
    // 복잡한 람다
    cout << "\n=== 복잡한 람다 ===" << endl;
    int threshold = 5;
    auto filter = [threshold](const vector<int>& vec) {
        vector<int> result;
        for (int n : vec) {
            if (n > threshold) {
                result.push_back(n);
            }
        }
        return result;
    };
    
    vector<int> filtered = filter(v);
    cout << threshold << "보다 큰 수: ";
    for (int n : filtered) cout << n << " ";
    cout << endl;
    
    // 람다를 변수로 저장 (function)
    cout << "\n=== function<> ===" << endl;
    function<int(int, int)> multiply = [](int a, int b) {
        return a * b;
    };
    cout << "multiply(4, 7) = " << multiply(4, 7) << endl;
    
    return 0;
}

