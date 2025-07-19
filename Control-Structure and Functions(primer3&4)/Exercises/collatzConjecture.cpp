#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n<=0){
        cin.clear();
        cin.ignore(1000,'\n');
    cout<<"please enter valid positve integer";
    return 0;
    }
    {
        /* code */
    }
    
    int steps=0;
    cout << n<<" ";
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
            cout << n<<"-->";
            steps++;
        }
        else
        {
            n = n * 3 + 1;
            cout << n<<"-->";
            steps++;
        }
    }

    cout<<"steps need: "<<steps;
    return 0;
}