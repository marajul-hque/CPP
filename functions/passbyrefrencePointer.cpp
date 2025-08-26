#include <iostream>
using namespace std;

void passByPointer(int *x)
{

    *x = *x + 10;
    cout << "outside the function: " << *x << endl;
}

int main()
{
    int a = 5;

    passByPointer(&a);
    cout << "Outside function (original): " << a << endl;

    return 0;
}