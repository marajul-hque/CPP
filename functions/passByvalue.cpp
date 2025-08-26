#include <iostream>
using namespace std;

void passByValue(int x) {
    x = x + 10; // modifying copy
    cout << "Inside function (value): " << x << endl;
}

int main() {
    int a = 5;
    passByValue(a);
    cout << "Outside function (original): " << a << endl;
    return 0;
}
