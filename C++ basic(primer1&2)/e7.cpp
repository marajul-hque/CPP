/*7. Write a program that asks the user to enter an hour value and a minute value.The
main() function should then pass these two values to a type void function that displays the two values in the format shown in the following sample run:
Enter the number of hours: 9
Enter the number of minutes: 28
Time: 9:28
*/

#include <iostream>
using namespace std;
void time(int h, int m)
{
    cout<<"Time: "<<h<<":"<<m<<endl;
}
int main()
{
    int hour;
    int minutes;
    cout << "Enter the number of hours :";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    time(hour,minutes);
}