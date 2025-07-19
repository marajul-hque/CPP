#include <iostream>
using namespace std;

int main()
{
    int n;
    int count = 1;
    cin >> n;

    while (n = n / 10)
    {
        count++;
    }

    cout << count << endl;
    return 0;
}