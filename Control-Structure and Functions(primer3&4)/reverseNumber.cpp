#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int reverseNumber = 0;



    while (number)
    {
        reverseNumber= reverseNumber*10 + (number%10);
        cout<<"reverse number is : "<<reverseNumber<<endl;
        number /= 10;
        cout<<"number is : "<<number<<endl;
    }
cout<<"reverse number is : "<<reverseNumber<<endl;
    return 0;
}