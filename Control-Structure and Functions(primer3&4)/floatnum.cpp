#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    cout.setf(ios_base::fixed, ios_base::floatfield); // This forces cout to use fixed-point notation (not scientific), and by default, C++ shows 6 digits after the decimal point.

    const double milion = 1.0e6;
    float tub = 10.0 / 3.0;
    cout << fixed << setprecision(20); // c++ by default show 6digit after decimal but this line help to increase or decrease

    cout << "tub is : " << tub << " tub*milion: " << tub * milion << endl;
    double mint = 10.0 / 3.0;
    cout << "mint is : " << mint << " tub*milion is : " << mint * milion;

    return 0;
}