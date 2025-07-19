#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int power = 1;
    while (power < n) {
        power *= 2;
    }
    cout << "Smallest power of 2 >= " << n << " is " << power << endl;
    return 0;
}