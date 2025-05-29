#include <iostream>

using namespace std;

int main()
{
    int age;
    cin >> age;
    switch (age)
    {
    case 18:
        cout << "you are 18" << endl;
        break;

    case 22:
        cout << "you are in university" << endl;

        break;

    case 2:
        cout << "youre kid " << endl;
        break;

    default:
        cout << "what do you wnat" << endl;
        break;
    }
}