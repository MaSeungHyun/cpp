#include <iostream>

using namespace std;

int main() {

    char name[256];
    cout << "Enter your name: ";
    cin >> name;
    printf("Hello %s Nice to meet you!", name);

    return 0;
}