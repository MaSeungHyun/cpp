#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {
        cout << "Person 생성: " << name << endl;
    }
    
    ~Person() {
        cout << "Person 소멸: " << name << endl;
    }
    
    void introduce() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

int main() {
    // unique_ptr: 단독 소유권
    cout << "=== unique_ptr ===" << endl;
    {
        unique_ptr<Person> ptr1(new Person("홍길동", 25));
        ptr1->introduce();
        
        // unique_ptr은 복사 불가, 이동만 가능
        unique_ptr<Person> ptr2 = move(ptr1);
        // ptr1은 이제 nullptr
        
        if (ptr1 == nullptr) {
            cout << "ptr1은 nullptr입니다." << endl;
        }
        
        ptr2->introduce();
    }  // 블록을 벗어나면 자동으로 메모리 해제
    
    cout << "\n=== make_unique ===" << endl;
    {
        auto ptr = make_unique<Person>("김철수", 30);
        ptr->introduce();
    }
    
    // shared_ptr: 공유 소유권
    cout << "\n=== shared_ptr ===" << endl;
    {
        shared_ptr<Person> ptr1 = make_shared<Person>("이영희", 28);
        cout << "참조 카운트: " << ptr1.use_count() << endl;
        
        {
            shared_ptr<Person> ptr2 = ptr1;  // 복사 가능
            cout << "참조 카운트: " << ptr1.use_count() << endl;
            
            ptr1->introduce();
            ptr2->introduce();
        }  // ptr2 소멸, 하지만 객체는 유지
        
        cout << "참조 카운트: " << ptr1.use_count() << endl;
        ptr1->introduce();
    }  // ptr1 소멸, 이제 객체 해제
    
    // weak_ptr: 약한 참조
    cout << "\n=== weak_ptr ===" << endl;
    {
        shared_ptr<Person> sharedPtr = make_shared<Person>("박민수", 35);
        weak_ptr<Person> weakPtr = sharedPtr;
        
        cout << "shared_ptr 참조 카운트: " << sharedPtr.use_count() << endl;
        
        // weak_ptr을 사용하려면 lock()으로 shared_ptr 생성
        if (auto lockedPtr = weakPtr.lock()) {
            lockedPtr->introduce();
            cout << "참조 카운트: " << sharedPtr.use_count() << endl;
        }
        
        sharedPtr.reset();  // 객체 해제
        
        if (weakPtr.expired()) {
            cout << "객체가 소멸되었습니다." << endl;
        }
    }
    
    // 배열과 스마트 포인터
    cout << "\n=== 배열과 스마트 포인터 ===" << endl;
    {
        auto arr = make_unique<int[]>(5);
        for (int i = 0; i < 5; i++) {
            arr[i] = i * 10;
        }
        
        cout << "배열: ";
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    cout << "\n프로그램 종료" << endl;
    
    return 0;
}

