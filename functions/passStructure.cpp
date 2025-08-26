#include<iostream>
using namespace std;
struct car
{
string brand;
int year;
};

void myFunction(car &c){
    cout<<"Brand: "<<c.brand<<", Year: "<<c.year<<'\n';

}
int main(){
    car mycar={"toyota", 2020};
    myFunction(mycar);
    return 0;
}