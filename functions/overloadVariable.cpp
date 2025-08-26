#include <iostream>
using namespace std;
int add(int a, int b, int c)
{

    return a + b + c;
}
int add(int x, int y)
{

    return x + y;
}
int main()
{

    cout << add(4, 5) << endl;

    cout << add(4, 6, 8) << endl;

    return 0;
}