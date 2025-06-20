#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter an integer: ";
    while (!(cin >> number))
    {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();            // clear the error flag
        cin.ignore(1000, '\n'); // discard invalid input from buffer
    }

    cout << "You entered: " << number << endl;
    return 0;
}