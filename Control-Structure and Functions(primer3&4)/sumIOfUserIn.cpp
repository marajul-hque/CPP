#include <iostream>
using namespace std;

int main()
{
    int num;
    int sum = 0;
    cout << "Enter number: ";
    while (cin >> num && num != 0) // cin>>num == false , when user input other than integer

    {
        sum += num;
    }

    cout << "Sum: " << sum << endl;

    return 0;
}