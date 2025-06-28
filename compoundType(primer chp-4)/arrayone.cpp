#include <iostream>
using namespace std;

int main()
{
    int yms[3];
    yms[0] = {7};
    yms[1] = {8};
    // as i did not initializedd yms[2], thats why yms[2]= a garbage valu 
    cout << "yms[2] :" << yms[2] <<endl;
    //but if i want to intialize all zero then ;

    int ymss[3]={}; // here alll value are zero

    cout<<"ymss[1] : "<<ymss[1];
    return 0;
}