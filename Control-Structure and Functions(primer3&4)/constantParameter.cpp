#include <iostream>
using namespace std;
bool isEqual(const string a, const string b)
{
    return a == b;
}
int main()
{

    string s1 = "hi";
    string s2 = "Hi";

    if (isEqual(s1, s2))
    {
        cout << "equal";
    }
    else
    {
        cout << "not equal";
    }

    return 0;
}