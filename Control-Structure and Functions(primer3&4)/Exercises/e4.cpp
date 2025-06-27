// 4. Write a program that asks the user to enter the number of seconds as an integer
// value (use type long, or, if available, long long) and that then displays the equivalent time in days, hours, minutes, and seconds. Use symbolic constants to represent
// the number of hours in the day, the number of minutes in an hour, and the number
// of seconds in a minute.The output should look like this:
// Enter the number of seconds: 31600000
// 31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds

#include <iostream>
using namespace std;
int const secondToMinute = 60;
int const secondToHour = secondToMinute * 60;
int const secondToday = 24 * secondToHour;
int main()
{
    long long second;
    long day;
    long hour;
    long minutes;
    long seconds;

    cout << "enter the number of second : ";
    cin >> second;
    day = second / secondToday;
    seconds = second % secondToday;
    hour = seconds / secondToHour;
    seconds = seconds % secondToHour;
    minutes = seconds / secondToMinute;
    seconds = seconds % secondToMinute;

    cout << second << " seconds = " << day << " days " << hour << " hours " << minutes << " minutes " << seconds << " seconds." << endl;

    return 0;
}