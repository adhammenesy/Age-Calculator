#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int calc(int age) { return age * 365; }
int hours(int age) { return calc(age) * 24; }
int minutes(int age) { return hours(age) * 60; }
int seconds(int age) { return minutes(age) * 60; }
int Milliseconds(int age) { return seconds(age) * 1000; }

string Date(int age) {
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    char output[50];
    datetime.tm_year -= age;
    mktime(&datetime);
    strftime(output, 50, "%d/%m/%Y", &datetime);
    return string(output);
}

int main()
{
    char playAgain;
    do {
        int age;
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 2);
        cout << "==============================\n";
        cout << "|                            |\n";
        cout << "|     Calculate Your Age     |\n";
        cout << "|                            |\n";
        cout << "==============================\n";
        SetConsoleTextAttribute(h, 6);
        cout << "Type Your Age: ";
        cin >> age;
        SetConsoleTextAttribute(h, 3);
        cout << "Days: " << calc(age) << " Hours: " << hours(age) << " Minutes: " << minutes(age) << " Seconds: " << seconds(age) << " Milliseconds: " << Milliseconds(age);
        cout << "\nDate: " << Date(age);
        SetConsoleTextAttribute(h, 7);
        cout << "\n\nDo you want to calculate again? (y/n): ";
        cin >> playAgain;
        system("cls");
    } while (playAgain == 'y' || playAgain == 'Y');
}
