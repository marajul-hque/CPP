#include <iostream>
#include <typeinfo>
using namespace std;
// auto sum(auto x, auto y)
// {
//     return x / y;
// }

int main()
{
    auto a = 0;
    auto b = 0.0;

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    auto m = -19 % 5;
    cout << m;
    // cout << "sum is: " << sum(4.5, 5);

    return 0;
}