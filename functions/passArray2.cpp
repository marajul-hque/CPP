#include<iostream>
using namespace std;

void myFunction(int* myNumbers)
{
    for (int  i = 0; i < 5; i++)
    {
     cout<<*(myNumbers+i)<<'\n';
    }
    

}
int main(){
    int mynumbers[5]={10,20,30,40,50};
    myFunction(mynumbers);
    return 0;
}