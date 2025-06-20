#include<iostream>
using namespace std;
void display(const int x) //here x is parameter
{
    //x=10; i cannot do it cause x is constant parameter  

    cout<<x<<endl;
}

int main(){
    display(5); //here 5 is argument
    return 0;
}