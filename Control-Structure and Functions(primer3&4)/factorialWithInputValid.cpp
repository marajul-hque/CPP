#include <iostream>
using namespace std;

int main()
{
    int n;
    long long l = 1;

    do
    {
        cout << "enter a non negative number: ";
        cin >> n;
        if (!cin)
        {
            cout << "Invalid input! Please enter an integer.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            n = -1; // force loop to repeat
        }
    } while (n < 0);

    if (n == 0)
    {
        cout << "fact is :" << l;

        return 0;
    }

    do
    {
        l = l * n;
        n--;

    } while (n >= 1);

    cout << l;

    return 0;
}