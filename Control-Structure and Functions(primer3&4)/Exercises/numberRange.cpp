// Exercise 5: Number Range Classifier
// Write a C++ program that takes an integer and classifies it into ranges: [0-10], [11-20], [21-30], or “Out of range” (if <0 or >30).

// Question: How would you optimize the else-if ladder to reduce redundancy? Could a switch statement be used instead?

// #include<iostream>
// using namespace std;

// int main(){
//     int number;
//     cout<<"Enter an interger: ";
//     cin>>number;
//     if (number>=0 && number <=10)
//     {
//         cout<<"range is :[0-10] "<<endl;
//     }
//     if (number>=11 && number <=20)
//     {
//         cout<<"range is :[11-20] "<<endl;
//     }
//     if (number>=21 && number <=30)
//     {
//         cout<<"range is :[21-30] "<<endl;
//     }
//     if (number<0 && number >30)
//     {
//         cout<<"out of ranges: "<<endl;
//     }

//     return 0;
// }next

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter an interger: ";
    cin >> n;
    if (n < 0 || n > 30)
        cout << "Out of range";
    else
    {
        switch ((n == 30) ? 2 : n / 10)
        {
        case 0:
            cout << "[0-10]";
            break;
        case 1:
            cout << "[11-20]";
            break;
        case 2:
            cout << "[21-30]";
            break;
        }
    }

    return 0;
}