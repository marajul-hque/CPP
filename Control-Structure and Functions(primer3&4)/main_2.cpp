#include <iostream>
using namespace std;

int main()
{

    char c = 65;                      // see you initialize with a char but
    cout << "char is :" << c << endl; // it print char character representation
    char d = 'A';
    cout << "char is : " << d << endl;              // thats why char actually store intger , the integer rep. character
    cout << "ASCII value of A: " << (int)d << endl; // thus you can generate ascci value of a character

    // here another tricks to convert int into possible char (int value to char).
    int x=100;
    cout<<"char value of : "<<x <<" is : "<<char(x)<<endl; 


    cout<<"hello\aworld"<<endl;

    return 0;
}