#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void clearScreen() { system("cls"); }

void showDate(struct tm* t) {
    cout << "Date: " << t->tm_mday << "/" << (t->tm_mon + 1) << "/" << (t->tm_year + 1900) << endl;
}

void show24Hour(struct tm* t) {
    cout << "Time: " << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << endl;
}

void show12Hour(struct tm* t) {
    int hour = t->tm_hour;
    string period = (hour >= 12) ? "PM" : "AM";
    if (hour == 0) hour = 12;
    else if (hour > 12) hour = hour - 12;
    cout << "Time: " << hour << ":" << t->tm_min << ":" << t->tm_sec << " " << period << endl;
}

int main() {
    int choice;
    cout << "====================" << endl;
    cout << "    DIGITAL CLOCK   " << endl;
    cout << "====================" << endl;
    cout << "1. 12-Hour (AM/PM)"   << endl;
    cout << "2. 24-Hour"           << endl;
    cout << "Enter 1 or 2: ";
    cin >> choice;

    while (true) {
        clearScreen();
        time_t now = time(0);
        struct tm* t = localtime(&now);
        cout << "====================" << endl;
        cout << "    DIGITAL CLOCK   " << endl;
        cout << "====================" << endl;
        showDate(t);
        if (choice == 1) show12Hour(t);
        else show24Hour(t);
        cout << "\nPress Ctrl+C to exit" << endl;
        Sleep(1000);
    }

    return 0;
}
