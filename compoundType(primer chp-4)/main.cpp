#include <iostream>
using namespace std;

int main()
{
    int nums[5] = {10, 20};

    for (int i = 0; i < 5; i++)
        cout << nums[i] << " ";
    cout << endl;
    int yams[3]; // Array of 3 integers
    yams[0] = 7; // Assign values
    yams[1] = 8;
    yams[2] = 6;
    int yamcosts[3] {20, 30, 5}; // Initialize at declaration
    cout << "Total yams = " << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2];
    cout << "Total yam expense is " << total << " cents.\n";
    cout << "Size of yams array = " << sizeof yams << " bytes.\n";
    cout << "Size of one element = " << sizeof yams[0] << " bytes.\n";

    cout << "array size : " << (sizeof yams) / (sizeof yams[0]) << " elements"; // this calculate total elements in array

    // cout<<yams.size(); // yams is a built-in array, not a vector

    return 0;
}
