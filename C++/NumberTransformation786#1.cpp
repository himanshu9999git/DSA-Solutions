#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>
#define vi vector<int>

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll x, y, a, b;
        cin >> x >> y;

        if (y % x != 0)
        {
            a = 0;
            b = 0;
        }
        else
        {
            a = 1;
            b = y / x;
        }
        cout << a << " " << b << endl;
    }

    return 0;
}