#include <iostream>
using namespace std;

int main()
{
    string a = "fuck";

    switch (2)
    {
    case 1:
        cout << a;
        break;

    case 2:

    default:
        cout << "also" << a;
        break;
    }

    return 0;
}