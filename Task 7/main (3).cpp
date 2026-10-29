#include <iostream>
using namespace std;

const long long MIN_BALANCE = 5000;

long long fare(int zone, bool peak)
{
    long long f;

    if (zone == 1)
        f = 1000;
    else if (zone == 2)
        f = 2000;
    else
        f = 3000;

    if (peak)
        f = f + f * 20 / 100;

    return f;
}

bool canTravel(long long balance, long long f)
{
    return balance - f >= MIN_BALANCE;
}

void deduct(long long &balance, long long f)
{
    if (canTravel(balance, f))
        balance -= f;
}

int main()
{
    long long balance = 10000;

    int zones[] = {1, 3, 2};
    bool peak[] = {false, true, false};

    for (int i = 0; i < 3; i++)
    {
        long long f = fare(zones[i], peak[i]);

        if (canTravel(balance, f))
        {
            deduct(balance, f);

            cout << "Fare Rs " << f / 100 << "."
                 << (f % 100 < 10 ? "0" : "")
                 << f % 100;

            cout << " Balance Rs " << balance / 100
                 << "." << (balance % 100 < 10 ? "0" : "")
                 << balance % 100 << '\n';
        }
        else
        {
            cout << "Denied (low balance) ";
            cout << "Balance Rs " << balance / 100
                 << "." << (balance % 100 < 10 ? "0" : "")
                 << balance % 100 << '\n';
        }
    }

    return 0;
}