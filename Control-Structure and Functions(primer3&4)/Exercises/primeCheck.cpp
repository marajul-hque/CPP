#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    long long n;
    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1)
    {
        cout << "not prime" << endl;
        return 0;
    }
    for (int i = 2; i < sqrt(n); i++)
    {

        if (n % i == 0)
        {
            cout << "not prime" << endl;
            return 0;
        }
    }
    cout << "prime.";
}