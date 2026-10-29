#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct TestCase {
    string zone, hour;
    int balance, recharge;
    string expected;
};

string fareLogic(string zone, string hourText,
                 int balance, int recharge) {
    int hour;
    stringstream ss(hourText);

    if (!(ss >> hour) || !(ss.eof()) ||
        hour < 0 || hour > 23)
        return "Invalid hour";

    if (zone != "Zone1" && zone != "Zone2" &&
        zone != "Zone3")
        return "Invalid zone";

    if (recharge < 0)
        return "Invalid recharge";

    if (balance < 0)
        return "Invalid balance";

    int fare;

    if (zone == "Zone1") fare = 10;
    else if (zone == "Zone2") fare = 20;
    else fare = 30;

    // Peak hours: 8:00-10:00 and 17:00-20:00
    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare += 5;

    int available = balance + recharge;

    if (available < fare)
        return "Insufficient balance";

    int remaining = available - fare;

    return "Fare=" + to_string(fare) +
           ", Remaining=" + to_string(remaining);
}

int main() {
    vector<TestCase> tests = {
        {"Zone1", "7", 100, 0, "Fare=10, Remaining=90"},
        {"Zone2", "9", 100, 0, "Fare=25, Remaining=75"},
        {"Zone3", "12", 100, 0, "Fare=30, Remaining=70"},
        {"Zone1", "8", 100, 0, "Fare=15, Remaining=85"},
        {"Zone1", "10", 100, 0, "Fare=10, Remaining=90"},
        {"Zone1", "17", 100, 0, "Fare=15, Remaining=85"},
        {"Zone1", "20", 100, 0, "Fare=10, Remaining=90"},
        {"Zone2", "12", 70, 0, "Fare=20, Remaining=50"},
        {"Zone4", "12", 100, 0, "Invalid zone"},
        {"Zone1", "12", 100, -10, "Invalid recharge"},
        {"Zone1", "abc", 100, 0, "Invalid hour"}
    };

    cout << "FARE LOGIC TEST RESULTS\n";
    cout << "---------------------------------------------\n";

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {
        string actual = fareLogic(
            tests[i].zone, tests[i].hour,
            tests[i].balance, tests[i].recharge
        );

        bool success = (actual == tests[i].expected);

        cout << "Test " << i + 1
             << " | Expected: " << tests[i].expected
             << " | Actual: " << actual
             << " | " << (success ? "PASS" : "FAIL")
             << endl;

        if (success) passed++;
    }

    cout << "---------------------------------------------\n";
    cout << "Tests Passed: " << passed
         << "/" << tests.size() << endl;

    // Hand calculation for five journeys
    int total = 10 + 25 + 30 + 15 + 20;
    cout << "Total fare for 5 journeys = Rs. "
         << total << endl;

    return 0;
}