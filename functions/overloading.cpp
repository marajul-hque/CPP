#include <iostream>
using namespace std;
double add(double x, double y)
{
    return x + y;
}

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int a = 4, b = 5;

    cout << add(5.2, 6.1) << endl;

    cout << add(a, b) << endl;
    return 0;
}