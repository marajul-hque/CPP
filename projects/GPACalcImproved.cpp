// study this after learning stl

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Subject
{
    string name;
    int credit;
    double gpa;
};

double creditPoint(int credit, double gpa)
{
    return credit * gpa;
}

int main()
{
    vector<Subject> subjects; // keeps the data for the summary
    int totalCredit = 0;
    double totalCpEarned = 0.0;

    // ---------- Input loop ----------
    while (true)
    {
        Subject s;

        cout << "\nEnter subject name (or \"stop\" to finish): ";
        cin >> s.name;
        if (s.name == "stop")
            break;

        cout << "Enter credit for " << s.name << ": ";
        cin >> s.credit;

        cout << "Enter earned GPA for " << s.name << ": ";
        cin >> s.gpa;

        subjects.push_back(s); // store for reporting
        totalCredit += s.credit;
        totalCpEarned += creditPoint(s.credit, s.gpa);
    }

    // ---------- Summary table ----------
    if (subjects.empty())
    {
        cout << "\nNo subjects entered.\n";
        return 0;
    }

    cout << "\n------------- GPA SUMMARY -------------\n";
    cout << left
         << setw(15) << "Subject"
         << setw(8) << "Credit"
         << setw(8) << "GPA"
         << setw(12) << "CredPts" << '\n';
    cout << string(43, '-') << '\n';

    for (const auto &s : subjects)
    {
        cout << left
             << setw(15) << s.name
             << setw(8) << s.credit
             << setw(8) << fixed << setprecision(2) << s.gpa
             << setw(12) << fixed << setprecision(2) << creditPoint(s.credit, s.gpa)
             << '\n';
    }

    cout << string(43, '-') << '\n';
    cout << setw(15) << "TOTAL"
         << setw(8) << totalCredit
         << setw(8) << " "
         << setw(12) << totalCpEarned << '\n';

    cout << "\nYour GPA is: "
         << fixed << setprecision(2)
         << (totalCpEarned / totalCredit) << endl;

    return 0;
}
