#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter a number between 1 and 10: ";
    while (true) {
        cin >> num;

        // Check if input failed (e.g., user typed a letter)
        if (cin.fail()) 
        
            {
            cin.clear(); // clear the error flag
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Invalid input. Please enter an integer between 1 and 10: ";
            continue;
        }

        // Check if number is in range
        if (num >= 1 && num <= 10) {
            break; // valid input
        } else {
            cout << "Out of range. Try again (1-10): ";
        }
    }

    cout << "You entered: " << num << endl;
    return 0;
}
