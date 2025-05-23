#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*  i have to make this calculator like : it will work like phone calc where
    user can input many number, any operation at a time*/
    char s;
    double a;
    double b;

    cout << "please enter first number: ";
    cin >> a;
    while (true)
    {
        cout << "enter the operation you want :";
        cin >> s;
        if (s != '+' || s != '-' || s != '*' || s != '/')
        {
            cout << "please enter correct operator"<<endl;
        }
        if (s == '+' || s == '-' || s == '*' || s == '/')
        {
            break;
        }
    }

    cout << "now enter second  number :";
    cin >> b;
    if (s == '+')
    {
        cout << "sum is :" << a + b << endl;
    }
    else if (s == '-')
    {
        cout << "substraction is :" << a - b << endl;
    }
    else if (s == '*')
    {
        cout << "multiplication is :" << a * b << endl;
    }
    else
    {
        cout << "division is :" << a / b << endl;
    }
}