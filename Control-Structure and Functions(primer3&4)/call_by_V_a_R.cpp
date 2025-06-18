// #include<iostream>
// using namespace std;
// void swap(int *x,int *y){
//     int temp= *x;
//     *x=*y;
//     *y=temp;
// }
// int main(){
// int a=5;
// int b=6;
//     cout <<"a is: "<<a<<", b is: "<<b<<endl;

// swap(&a,&b);  

//     cout <<"a is: "<<a<<", b is: "<<b<<endl;

//     return 0;
// }
#include<iostream>
using namespace std;
void swap(int &x,int &y){
    int temp= x;
    x=y;
    y=temp;
}
int main(){
int a=5;
int b=6;
    cout <<"a is: "<<a<<", b is: "<<b<<endl;

swap(a,b);  

    cout <<"a is: "<<a<<", b is: "<<b<<endl;

    return 0;
}