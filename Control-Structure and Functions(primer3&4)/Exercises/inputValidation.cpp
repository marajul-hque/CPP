#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n >= 1 && n <= 10)
    {
        cout << "you choose correct";
    }
    else
    {
        while (n <= 1 || n >= 10)
        {
            cout << "please enter correct";
            cin >> n;
            if (n >= 1 && n <= 10)
            {
                cout << "you choose correct.";
            }
            return 0;
        }
    }

    return 0;
}