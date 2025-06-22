#include <iostream>
#include <climits>
#include <limits>
using namespace std;

int main()
{
    cout << "min int : " << INT_MIN << endl; // THEY ARE C TYPE MIN MAX
    cout << "max int :" << INT_MAX << endl;
    cout << "min int :" << numeric_limits<int>::min() << endl; // THEY ARE C++ TYPE MIN MAX
    cout << "max int : " << numeric_limits<int>::max() << endl;
    cout << "size of : " << sizeof(int) << " bytes " << endl; // how many bytes of memory does it  take

    cout << "min shrot :" << numeric_limits<short>::min() << endl;
    cout << "max short : " << numeric_limits<short>::max() << endl;
    cout << "size short : " << sizeof(short) << "bytes " << endl; // how many bytes of memory does it  take

    cout << "min long :" << numeric_limits<long>::min() << endl;
    cout << "max long : " << numeric_limits<long>::max() << endl;
    cout << "size of long : " << sizeof(long) << "bytes " << endl; // how many bytes of memory does it  take

    cout << "min long long :" << numeric_limits<long long>::min() << endl;
    cout << "max int : " << numeric_limits<long long>::max() << endl;
    cout << "size of : " << sizeof(long long) << "bytes " << endl; // how many bytes of memory does it  take

    cout << "min  :" << numeric_limits<unsigned int>::min() << endl;
    cout << "max  : " << numeric_limits<unsigned int>::max() << endl;
    cout << "size of : " << sizeof(unsigned int) << "bytes " << endl; // how many bytes of memory does it  take

    cout <<"short"<<endl;
    cout << "min  :" << numeric_limits<unsigned short>::min() << endl;
    cout << "max  : " << numeric_limits<unsigned short>::max() << endl;
    cout << "size of : " << sizeof(unsigned short) << "bytes " << endl; // how many bytes of memory does it  take

    cout << "long :" << endl;

    cout << "min  :" << numeric_limits<unsigned long>::min() << endl;
    cout << "max  : " << numeric_limits<unsigned long>::max() << endl;
    cout << "size of : " << sizeof(unsigned long) << "bytes " << endl; // how many bytes of memory does it  take

    cout << "long long : " << endl;
    cout << "min  :" << numeric_limits<unsigned long long>::min() << endl;
    cout << "max  : " << numeric_limits<unsigned long long>::max() << endl;
    cout << "size of : " << sizeof(unsigned long long) << "bytes " << endl; // how many bytes of memory does it  take

    return 0;
}