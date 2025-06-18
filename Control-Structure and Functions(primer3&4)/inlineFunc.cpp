#include <iostream>
#include <chrono>
using namespace std;

inline int product1(int a, int b) // here inline request compiler to replace function call with a*b;
{

    return a * b;
}

int product2(int a, int b)

{

    return a * b;
}

int main()
{
    int a = 5, b = 6;
    cout << "product1 is: " << product1(a, b) << endl;

    auto start = chrono::high_resolution_clock::now();

    volatile int result = 0;

    for (int i = 0; i < 100000000; i++)
    {
        result += product1(a, b);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    cout << "execution time :" << duration.count() << " ms\n";

    int c = 5, d = 6;
    cout << "product2 is: " << product2(c, d) << endl;

    auto start1 = chrono::high_resolution_clock::now();

    volatile int result2 = 0;

    for (int i = 0; i < 100000000; i++)
    {
        result2 += product2(a, b);
    }
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration1 = end1 - start1;

    cout << "execution time :" << duration1.count() << " ms\n";

    return 0;
}