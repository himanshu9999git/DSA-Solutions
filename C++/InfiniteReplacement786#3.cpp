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
        string s, t;
        cin >> s;
        cin >> t;

        bool flaga = false;
        bool flago = false;

        for (ll i = 0; i < t.length(); i++)
        {
            if (t[i] == 'a')
                flaga = true;

            if (t[i] != 'a')
                flago = true;
        }
        if (flaga && flago)
            cout << -1;

        else if (!flaga && flago)
        {
            ll k = pow(2, s.length());
            cout << k;
        }

        else if (flaga && !flago)
        {
            if (t.length() == 1)
                cout << 1;

            else
                cout << -1;
        }

        cout << endl;
    }

    return 0;
}