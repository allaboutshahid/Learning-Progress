#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;

int main()
{
    while(true)
    {
        time_t now = time(0);
        tm *localTime = localtime(&now);

        system("cls");

        cout << "==========================" << endl;
        cout << "      DIGITAL CLOCK       " << endl;
        cout << "==========================" << endl;

        cout << endl;

        cout << "Time: "
             << setfill('0') << setw(2) << localTime->tm_hour << ":"
             << setfill('0') << setw(2) << localTime->tm_min << ":"
             << setfill('0') << setw(2) << localTime->tm_sec
             << endl;

        cout << "Date: "
             << setfill('0') << setw(2) << localTime->tm_mday << "/"
             << setfill('0') << setw(2) << localTime->tm_mon + 1 << "/"
             << localTime->tm_year + 1900
             << endl;

        Sleep(1000);
    }

    return 0;
}