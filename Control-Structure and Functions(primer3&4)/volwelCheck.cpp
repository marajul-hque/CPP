#include <iostream>
using namespace std;

int main()
{
    char vowel;
    cout << "Enter a Character: ";
    cin >> vowel;

    switch (vowel)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        cout << vowel << " is a vowel." << endl;
        break;

    default:
        cout << vowel << " is not a vowel." << endl;
        break;
    }

    return 0;
}