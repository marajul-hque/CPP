#include<iostream>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int count=0;
    do
    {
        if (s[count] !='\0')
        {
            count++;
            /* code */
        }
        else break;
        
        /* code */
    } while (true);
    
    cout << "Number of characters: " << count << endl;

    return 0;
}