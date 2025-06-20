#include<iostream>
using namespace std;

float moneyRecieved(int curentmoney, float factor=1.04){
return curentmoney*factor;
}

int main(){
    int money =10000;
    cout<<"you have "<<money<<" so you recived : "<<moneyRecieved(money)<<endl;
    cout<<"for disable people "<<money<<" they recived: " <<moneyRecieved(money,1.1);
    
    return 0;
}