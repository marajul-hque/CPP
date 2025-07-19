#include <iostream>
using namespace std;

int main()
{
    string username, password;
    cout << "Enter usename: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == "admin")
    {
        if (password == "admin123")
        {
            cout << "login successful!";
        }

        else
        {
            cout << "incorrect password!";
        }
    }
    else
    {
        cout << "invalid username!";
    }

    return 0;
}