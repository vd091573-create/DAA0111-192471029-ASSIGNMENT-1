#include <iostream>
using namespace std;

const double BASE_FARE = 10.0;
const double FARE_PER_KM = 2.0;

class MetroFare {
public:
    double calculateFare(double distance) {
        return BASE_FARE + (distance * FARE_PER_KM);
    }
};

int main() {
    MetroFare metro;
    double distance;

    cout << "Enter journey distance in km: ";
    cin >> distance;

    if (distance < 0) {
        cout << "Invalid distance!" << endl;
    } else {
        cout << "Metro Fare: Rs. "
             << metro.calculateFare(distance) << endl;
    }

    return 0;
}