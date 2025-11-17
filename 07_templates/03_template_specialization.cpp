#include <iostream>
#include <cstring>

using namespace std;

// 일반 템플릿
template <typename T>
class Printer {
public:
    void print(T value) {
        cout << "일반 타입: " << value << endl;
    }
};

// 템플릿 특수화 (char*)
template <>
class Printer<char*> {
public:
    void print(char* value) {
        cout << "문자열: \"" << value << "\"" << endl;
    }
};

// 템플릿 특수화 (bool)
template <>
class Printer<bool> {
public:
    void print(bool value) {
        cout << "불린: " << (value ? "true" : "false") << endl;
    }
};

// 함수 템플릿과 특수화
template <typename T>
T maximum(T a, T b) {
    cout << "(일반 템플릿) ";
    return (a > b) ? a : b;
}

// const char* 특수화
template <>
const char* maximum<const char*>(const char* a, const char* b) {
    cout << "(문자열 특수화) ";
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    cout << "=== 클래스 템플릿 특수화 ===" << endl;
    Printer<int> intPrinter;
    Printer<double> doublePrinter;
    Printer<char*> stringPrinter;
    Printer<bool> boolPrinter;
    
    intPrinter.print(42);
    doublePrinter.print(3.14);
    
    char str[] = "Hello World";
    stringPrinter.print(str);
    
    boolPrinter.print(true);
    boolPrinter.print(false);
    
    cout << "\n=== 함수 템플릿 특수화 ===" << endl;
    cout << "max(10, 20) = " << maximum(10, 20) << endl;
    cout << "max(\"apple\", \"banana\") = " << maximum("apple", "banana") << endl;
    
    return 0;
}

