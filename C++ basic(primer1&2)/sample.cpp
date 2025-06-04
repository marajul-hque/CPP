#include<iostream>
 using namespace std; 
int main() { int carrots; // Declare variable
 cout << "How many carrots do you have? "; 
 cin >> carrots; // Get user input
cout << "Here are two more. ";
carrots = carrots + 2; // Update variable
cout << "Now you have " << carrots << " carrots." << endl; 
    return 0; 
    }