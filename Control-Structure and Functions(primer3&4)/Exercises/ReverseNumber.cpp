#include <iostream>
using namespace std;

int main()
{
    int n;
    int reverseNum = 0;
    cin >> n;
    while (n != 0)
    {
        reverseNum = reverseNum * 10 + n % 10;
        n = n / 10;
    }
    cout << reverseNum;

    return 0;
}

// what about 100=001? so then you have to use string
