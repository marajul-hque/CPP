#include <iostream>
using namespace std;

int main() {
    char choice;
    do {
        cout << "Menu:\n1. Option A\n2. Option B\n3. Exit\nEnter choice (1-3): ";
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "You selected Option A." << endl;
                break;
            case '2':
                cout << "You selected Option B." << endl;
                break;
            case '3':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != '3');
    return 0;
}