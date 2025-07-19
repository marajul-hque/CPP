// Exercise 3: Sum Until Negative
// Write a C++ program that reads integers from the user until a negative number is entered, then prints their sum.

// Question: How would you ensure the program handles invalid input? Could cin fail, and how would you detect it?

#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    // int sum = 0;
    // while (cin >> n && n >= 0)
    // {
    //     sum = sum + n;
    // }
    // cout << "sum is: " << sum << endl;

    cin >> s;

    if (!cin)
    {
        cout << "Invalid input!" << endl;
    }

    return 0;
}