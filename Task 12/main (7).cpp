#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;

enum Zone { ZONE1, ZONE2, ZONE3, AIRPORT };

const int fares[] = {10, 20, 30, 60};
const int PEAK_SURCHARGE = 5;

class MonthlyPass {
public:
    Zone zone1, zone2;
    bool active;

    MonthlyPass(Zone a, Zone b) {
        zone1 = a;
        zone2 = b;
        active = true;
    }

    bool covers(Zone z) {
        return active && (z == zone1 || z == zone2);
    }
};

class SmartCard {
public:
    double balance;

    SmartCard(double b) {
        balance = b;
    }

    double travel(Zone z, int hour, bool weekend,
                  MonthlyPass* pass = nullptr) {
        if (z < ZONE1 || z > AIRPORT ||
            hour < 0 || hour > 23) {
            cout << "Invalid input\n";
            return -1;
        }

        if (pass != nullptr && pass->covers(z)) {
            cout << "Monthly pass: Free journey\n";
            return 0;
        }

        double fare = fares[z];

        bool peak = (hour >= 8 && hour < 10) ||
                    (hour >= 17 && hour < 20);

        if (weekend) {
            fare *= 0.90;  // 10% discount, no peak surcharge
        } else if (peak) {
            fare += PEAK_SURCHARGE;
        }

        if (balance < fare) {
            cout << "Insufficient balance\n";
            return -1;
        }

        balance -= fare;
        cout << fixed << setprecision(2);
        cout << "Fare: Rs." << fare
             << ", Balance: Rs." << balance << '\n';

        return fare;
    }
};

int main() {
    SmartCard card(200);
    MonthlyPass pass(ZONE1, ZONE2);

    cout << "Normal journey:\n";
    card.travel(ZONE1, 12, false);

    cout << "\nPeak journey:\n";
    card.travel(ZONE2, 9, false);

    cout << "\nWeekend Airport journey:\n";
    card.travel(AIRPORT, 9, true);

    cout << "\nMonthly pass journey:\n";
    card.travel(ZONE1, 12, false, &pass);

    cout << "\nWeekend Zone 3 journey:\n";
    card.travel(ZONE3, 12, true);

    return 0;
}