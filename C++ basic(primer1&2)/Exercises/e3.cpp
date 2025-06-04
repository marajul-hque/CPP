/*3. Write a C++ program that uses three user-defined functions (counting main() as
one) and produces the following output:
Three blind mice
Three blind mice
See how they run
See how they run*/
#include<iostream>
using namespace std;
void mice(){
    cout<<"Three blind mice"<<endl;

}
void run(){
    cout<<"see they run"<<endl;
}

int main(){
mice();
mice();
run();
run();
}