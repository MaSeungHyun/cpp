#include <iostream>
#include <stdexcept>

using namespace std;

// 기본 클래스 템플릿
template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}
    
    T getValue() const {
        return value;
    }
    
    void setValue(T v) {
        value = v;
    }
    
    void print() const {
        cout << "Box contains: " << value << endl;
    }
};

// Pair 클래스 템플릿
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
    
    void print() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

// 동적 배열 클래스 템플릿
template <typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int size;

public:
    DynamicArray(int cap = 10) : capacity(cap), size(0) {
        data = new T[capacity];
    }
    
    ~DynamicArray() {
        delete[] data;
    }
    
    void push_back(T value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }
    
    T get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
    
    int getSize() const {
        return size;
    }
    
    void print() const {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

private:
    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};

// 스택 클래스 템플릿
template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int top;

public:
    Stack(int cap = 10) : capacity(cap), top(-1) {
        data = new T[capacity];
    }
    
    ~Stack() {
        delete[] data;
    }
    
    void push(T value) {
        if (top >= capacity - 1) {
            throw overflow_error("Stack overflow");
        }
        data[++top] = value;
    }
    
    T pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow");
        }
        return data[top--];
    }
    
    T peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return data[top];
    }
    
    bool isEmpty() const {
        return top == -1;
    }
    
    int getSize() const {
        return top + 1;
    }
};

int main() {
    cout << "=== Box 클래스 ===" << endl;
    Box<int> intBox(42);
    Box<double> doubleBox(3.14);
    Box<string> stringBox("Hello");
    
    intBox.print();
    doubleBox.print();
    stringBox.print();
    
    cout << "\n=== Pair 클래스 ===" << endl;
    Pair<int, int> point(10, 20);
    Pair<string, int> nameAge("홍길동", 25);
    Pair<double, string> priceItem(19.99, "Book");
    
    point.print();
    nameAge.print();
    priceItem.print();
    
    cout << "\n=== DynamicArray 클래스 ===" << endl;
    DynamicArray<int> arr;
    for (int i = 1; i <= 15; i++) {
        arr.push_back(i * 10);
    }
    arr.print();
    cout << "크기: " << arr.getSize() << endl;
    cout << "arr[5] = " << arr.get(5) << endl;
    
    cout << "\n=== Stack 클래스 ===" << endl;
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "스택 크기: " << stack.getSize() << endl;
    cout << "Top: " << stack.peek() << endl;
    
    while (!stack.isEmpty()) {
        cout << "Pop: " << stack.pop() << endl;
    }
    
    return 0;
}

