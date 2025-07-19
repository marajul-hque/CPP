#include <iostream>
using namespace std;
int main()
{
    int n, maxNum,num;
    cout << "Enter how many numbers : ";
    cin >> n;
    cout<<"Now enter the numbers: ";
    cin>>maxNum;
    for (int i = 0; i < n-1; i++)
    {
        cin >> num;

        if (num > maxNum)
        {
            maxNum = num;
        }
    }
    cout<<"max number is:"<<maxNum<<endl;
}