#include <iostream>
using namespace std;

int main()
{
    int i = 9;
    int j = 5;
    cout << (float)i / j << endl; // here i and j are int , if i dont force them typecast into float thrn it will not show decimal part

    char c = 'C';
    cout << (int)c << endl;
    cout << "yes, the code of c is : " << static_cast<int>(c) << endl;

    int x{3.9832};
    cout << x;

    return 0;
}