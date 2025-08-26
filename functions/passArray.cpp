#include <iostream>
using namespace std;
int ArraySum(int* arr, int size)
{
    
    int sum = 0;
    for (int i = 0; i <size ; i++)
    {
        sum = sum + *(arr+i);
    }
    return sum;
}
int main()
{
    int arr[5] = {1, 3, 5, 8, 6};

    cout << "Sum: " << ArraySum(&arr[0],5) << endl;

    return 0;
}

// arr is a pointer holding address 1000 (address of first element)
// When you write arr[i], the compiler automatically converts it to *(arr + i)
// Pointer arithmetic: arr + i calculates the memory address:

// arr + 0 = 1000 (first element)
// arr + 1 = 1004 (second element)
// arr + 2 = 1008 (third element)
// etc.


// Dereference: * gets the value at that address

// So when you write arr[2]:

// Compiler converts to *(arr + 2)
// Calculates address: 1000 + 2×4 = 1008
// Dereferences: *(1008) = 5

// The magic is that C++ lets you use array notation [] with pointers! The bracket syntax automatically does the pointer arithmetic and dereferencing for you.
// This is why the function works even though arr is just a pointer - the [] operator works on any pointer, not just arrays. It's the same mechanism that makes arrays work in the first place!