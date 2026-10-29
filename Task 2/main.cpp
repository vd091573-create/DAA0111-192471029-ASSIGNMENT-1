#include <iostream>
using namespace std;

constexpr int INNER_FARE = 10;
constexpr int MIDDLE_FARE = 20;
constexpr int OUTER_FARE = 30;
constexpr int MIN_BALANCE = 50;
constexpr int PEAK_RATE = 120;

enum class Zone {
    Inner = 1,
    Middle = 2,
    Outer = 3
};

int main() {
    const int balance = 200;
    int zone, hour, fare;

    cout << "Enter zone (1-Inner, 2-Middle, 3-Outer): ";
    cin >> zone;

    cout << "Enter hour: ";
    cin >> hour;

    if (zone == 1)
        fare = INNER_FARE;
    else if (zone == 2)
        fare = MIDDLE_FARE;
    else if (zone == 3)
        fare = OUTER_FARE;
    else {
        cout << "Invalid zone";
        return 0;
    }

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20))
        fare = fare * PEAK_RATE / 100;

    cout << "Fare: Rs. " << fare << endl;

    if (balance - fare >= MIN_BALANCE)
        cout << "Journey allowed";
    else
        cout << "Journey not allowed";

    return 0;
}