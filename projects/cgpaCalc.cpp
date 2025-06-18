#include <iostream>
#include<iomanip>
using namespace std;

double CreditPoint(int subjectcredit, double earnedGpa)
{
    return subjectcredit * earnedGpa;
}

int main()
{
    int a;
    cout << "enter number of subject/s: ";
    cin >> a;

    int totalCredit = 0;
    double creditearned = 0;

    while (a--)
    {

        int credit;
        double EarnedGpa;
        cout << "Enter subject credit: ";
        cin >> credit;
        cout << "Enter earned gpa: ";
        cin >> EarnedGpa;
        totalCredit = totalCredit + credit;
        creditearned = creditearned + CreditPoint(credit, EarnedGpa);
    }


    cout<<fixed<<setprecision(2);
    cout << "your gpa is : " << creditearned / totalCredit << endl;

    return 0;
}