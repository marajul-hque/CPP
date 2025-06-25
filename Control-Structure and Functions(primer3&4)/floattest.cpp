#include <iostream>
using namespace std;

int main()
{
    float f = 10.3;
    double d = 10.25e+50;      // double range is ±1e308
    long double ld = 10e+542l; // long double range is ±1e4932 and you must have to write l or L after the number

    cout << "double is : " << d << endl;
    cout << ld;

    float a = 2.34E+7f;
    float b = a + 1.0f;

    cout << "a = " << a << endl;
    cout << "b-a = " << b - a << endl;

    return 0;
}