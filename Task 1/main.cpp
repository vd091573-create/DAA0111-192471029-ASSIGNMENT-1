#include <iostream>
using namespace std;

int main() {
    int balance, zone, type, hour;
    int fare;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Enter zone (1, 2, 3): ";
    cin >> zone;

    cout << "Enter type (1-Regular, 2-Student, 3-Senior): ";
    cin >> type;

    cout << "Enter hour: ";
    cin >> hour;

    if (zone == 1)
        fare = 10;
    else if (zone == 2)
        fare = 20;
    else if (zone == 3)
        fare = 30;
    else {
        cout << "Invalid zone";
        return 0;
    }

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20))
        fare = fare * 120 / 100;

    if (type == 2 || type == 3)
        fare = fare * 90 / 100;

    cout << "Fare: Rs. " << fare << endl;

    if (balance - fare >= 50) {
        balance = balance - fare;
        cout << "Journey successful!" << endl;
        cout << "Remaining balance: Rs. "
             << balance;
    }
    else {
        cout << "Insufficient balance!";
    }

    return 0;
}