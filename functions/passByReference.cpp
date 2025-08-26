#include<iostream>
using namespace std;
void passbyref(int &x){
    x=x+10;
    cout<<"inside the function value of x:" <<x<<endl;
}

int main(){
    int x=5;
    passbyref(x);

    cout<<"outside the function: "<<x<<endl;
    return 0;
}