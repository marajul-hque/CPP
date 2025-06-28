#include <iostream>
using namespace std;

int main()
{
    // here how cin takes input: cin get terminated when it see any space, tab etc
    // ex:
    //  string name;
    // cin >> name;
    // Typing:
    // Ali Khan

    // name gets "Ali"
    // The space stops the input.
    // "Khan\n" remains in the input buffer.

    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert << " for you, " << name << ".\n";
    return 0;
}