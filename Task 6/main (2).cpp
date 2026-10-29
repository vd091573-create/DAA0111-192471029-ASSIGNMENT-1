#include <iostream>
#include <iomanip>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr int BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long fare(Zone z, bool peak)
{
    long long f = 0;

    switch (z)
    {
        case Zone::Inner:
            f = BASE_PAISE[0];
            break;

        case Zone::Middle:
            f = BASE_PAISE[1];
            break;

        case Zone::Outer:
            f = BASE_PAISE[2];
            break;
    }

    if (peak)
        f += f * PEAK_SURCHARGE_PERCENT / 100;

    return f;
}

bool canTravel(long long balance, long long f)
{
    return (balance - f) >= MIN_BALANCE_PAISE;
}

int main()
{
    long long balance = 10000; // Rs. 100.00

    struct Trip
    {
        Zone zone;
        bool peak;
    };

    Trip trips[] = {
        {Zone::Inner, false},
        {Zone::Outer, true},
        {Zone::Middle, false}
    };

    for (const Trip& t : trips)
    {
        long long f = fare(t.zone, t.peak);

        if (canTravel(balance, f))
        {
            balance -= f;

            cout << fixed << setprecision(2);
            cout << "Fare Rs "
                 << f / 100.0
                 << " balance Rs "
                 << balance / 100.0 << '\n';
        }
        else
        {
            cout << "Denied (low balance) ";
            cout << "balance Rs "
                 << balance / 100.0 << '\n';
        }
    }

    return 0;
}