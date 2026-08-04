#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int length;

    cout << "Enter password length: ";
    cin >> length;

    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%";

    srand(time(0));

    string password = "";

    for(int i = 0; i < length; i++)
    {
        password += chars[rand() % chars.length()];
    }

    cout << "Generated Password: " << password << endl;

    return 0;
}