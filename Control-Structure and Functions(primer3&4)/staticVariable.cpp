#include <iostream>
using namespace std;

int main()
{

    cout << "static a :" << endl;

    for (size_t i = 0; i < 10; i++)
    {

        static int a = 2;
        cout << a << " a++ is: ";
        cout << a++ << endl;
    }

    cout << "non static a :" << endl;

    for (size_t i = 0; i < 10; i++)
    {

         int a = 2;
        cout << a << " a++ is: ";
        cout << a++ << endl;
    }

    return 0;
}