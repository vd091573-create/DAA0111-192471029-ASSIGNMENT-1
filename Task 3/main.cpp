#include <iostream>
#include <climits>
using namespace std;

int main() {
    long long balance = 20000; 
    int fare = 3000;
    int zone = 3;
    int hour = 9;
    bool peak = (hour >= 8 && hour < 10);
    long long journeys = 3000000;

    if (peak)
        fare = fare * 120 / 100;

    balance = balance - fare;

    cout << "Fare in paise: " << fare * 100 << endl;
    cout << "Remaining balance in paise: " 
         << balance << endl;

    cout << "Zone: " << zone << endl;
    cout << "Peak hour: " << peak << endl;
    cout << "Daily journeys: " << journeys << endl;

    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) 
         << " bytes" << endl;
    cout << "Size of bool: " << sizeof(bool) << " bytes" << endl;

    cout << "Maximum int: " << INT_MAX << endl;

    return 0;
}