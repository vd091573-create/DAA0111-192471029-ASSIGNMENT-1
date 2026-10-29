#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

int main()
{
    string name;
    int zone;
    double fare, balance;

    cout << "Enter passenger name: ";
    getline(cin, name);

    cout << "Enter zone (1-3): ";

    while (!(cin >> zone) || zone < 1 || zone > 3)
    {
        cout << "Invalid zone. Enter 1, 2, or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter fare (Rs): ";

    while (!(cin >> fare) || fare < 0)
    {
        cout << "Invalid fare. Enter a valid amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter card balance (Rs): ";

    while (!(cin >> balance) || balance < 0)
    {
        cout << "Invalid balance. Enter a valid amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << fixed << setprecision(2);

    cout << "\n----- JOURNEY REPORT -----\n";
    cout << "Passenger : " << name << '\n';
    cout << "Zone      : " << zone << '\n';
    cout << "Fare      : Rs " << fare << '\n';
    cout << "Balance   : Rs " << balance << '\n';

    if (balance - fare >= 50.00)
        cout << "Status    : Travel Allowed\n";
    else
        cout << "Status    : Denied (Low Balance)\n";

    return 0;
}