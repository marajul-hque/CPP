#include<iostream>
#include<thread>
using namespace std;

int main(){
    int countdown=3;
    while (countdown>0)
    {
        cout<<countdown<<endl;
        this_thread::sleep_for(chrono::seconds(1)); // wait 2 seconds

        countdown--;
    }

    cout<<"happy new year"<<endl;
    
    return 0;
}