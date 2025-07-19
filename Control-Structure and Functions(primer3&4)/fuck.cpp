#include <iostream>
using namespace std;
enum Color
{
    RED,
    GREEN,
    BLUE
};
int main()
{
    int choice;
    cout << "Choose a color :";
    cin >> choice;
    switch (choice)
    {
    case RED:
        cout << "You choose Red," << endl;

        break;
    case GREEN:
        cout << " you choose green." << endl;
        break;
    case BLUE:
        cout << "you choose blue." << endl;
        break;
    default:
        cout << "Invalid choice! " << endl;
        break;
    }
    return 0;
}