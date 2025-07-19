#include <iostream>
using namespace std;

int main()
{
    string text;
    cout << "Enter a string : ";
    getline(cin, text);
    int i = 0;
    int vowel = 0;
    while (i < text.length())
    {
        char c = tolower(text[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowel++;
        }

        i++;
    }
    cout << "Number of vowels: " << vowel << endl;
    return 0;
}