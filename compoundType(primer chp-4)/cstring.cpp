#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char bird[11] = "doyel"; // string
    cout << bird << endl;
    char fish[] = "pomfret"; // string
    cout << fish << endl;
    char birds[11] = {'d', 'e', 'a', 'l', '\0'}; // without \0 it is char array
    cout << birds << endl;

    char name[] = {'m', 'a', 'r', 'a', '\0', 'j', 'u', 'l', '\0'}; // \0 use as string terminator
    cout << name << endl;

    char names[] = {'m', 'a', 'r', 'a', 'j', 'u', 'l', '\0'}; // \0 use as string terminator

    names[3] = {'\0'}; // it terminate string on 4th position.
    cout << names << endl;

    cout << strlen(name)<<endl; // this function count visible char till \0 . but exclude \0
    cout << strlen("marajul") << endl;
    return 0;
}