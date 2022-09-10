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
        ll n, m;
        cin >> n >> m;

        if (n == 1 || m == 1 || (n % 2 == 1 && m % 2 == 1))
            cout << -1 << endl;

        else
        {
            if (n % 2 == 0 && m % 2 == 0)
            {
                for (ll i = 0; i < n / 2; i++)
                {
                    cout << "a";
                }
                for (ll i = 0; i < m; i++)
                {
                    cout << "b";
                }
                for (ll i = 0; i < n / 2; i++)
                {
                    cout << "a";
                }

                cout << endl;

                for (ll i = 0; i < m / 2; i++)
                {
                    cout << "b";
                }
                for (ll i = 0; i < n; i++)
                {
                    cout << "a";
                }
                for (ll i = 0; i < m / 2; i++)
                {
                    cout << "b";
                }
            }

            else if (n % 2 == 0 && m % 2 == 1)
            {
                for (ll i = 0; i < n / 2; i++)
                {
                    cout << "a";
                }
                for (ll i = 0; i < m; i++)
                {
                    cout << "b";
                }
                for (ll i = 0; i < n / 2; i++)
                {
                    cout << "a";
                }

                cout << endl;

                for (ll i = 0; i < m / 2; i++)
                {
                    cout << "b";
                }
                for (ll i = 0; i < n / 2; i++)
                {
                    cout << "a";
                }

                cout << "b";

                for (ll i = 0; i < n / 2; i++)
                {
                    cout << "a";
                }
                for (ll i = 0; i < m / 2; i++)
                {
                    cout << "b";
                }
            }

            else if (n % 2 == 1 && m % 2 == 0)
            {
                for (ll i = 0; i < m / 2; i++)
                {
                    cout << "b";
                }
                for (ll i = 0; i < n; i++)
                {
                    cout << "a";
                }
                for (ll i = 0; i < m / 2; i++)
                {
                    cout << "b";
                }

                cout << endl;

                for (ll i = 0; i < n / 2; i++)
                {
                    cout << "a";
                }
                for (ll i = 0; i < m / 2; i++)
                {
                    cout << "b";
                }

                cout << "a";

                for (ll i = 0; i < m / 2; i++)
                {
                    cout << "b";
                }
                for (ll i = 0; i < n / 2; i++)
                {
                    cout << "a";
                }
            }
            cout<<endl;
        }
    }

    return 0;
}