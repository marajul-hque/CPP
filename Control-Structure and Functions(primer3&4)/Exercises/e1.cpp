/*1. Write a short program that asks for your height in integer inches and then converts
your height to feet and inches. Have the program use the underscore character to
indicate where to type the response.Also use a const symbolic constant to represent the conversion factor*/

// #include <iostream>
// using namespace std;
// int main()
// {
//     int heightInInches;
//     const auto factors = 12;
//     cout << "Enter your height in inches : ";
//     cin >> heightInInches;
//     cout << "your height is: " << (int)heightInInches / factors <<
//      " foot " << "and " << (double)( (double)heightInInches
//       / factors-heightInInches / factors )*12 << " inches "<< endl;
// }

// alternative

#include <iostream>
using namespace std;
int const factor = 12;
int main()
{
    int heightInInches;
    cout << "enter your heught in inches:__\b\b"; // move curseor left back by two . if one \b then one back , 3 three .........
    cin >> heightInInches;
    int feet = heightInInches / factor;
    double inches = heightInInches % factor;
    cout << "your height is : " << feet << " feet and " << inches << " inches. " << endl;
    return 0;
}