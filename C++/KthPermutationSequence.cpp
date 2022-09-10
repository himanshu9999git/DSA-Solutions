#include <bits/stdc++.h>
using namespace std;

int factorial(vector<int> &fact, int n)
{
    if (n == 0)
        return 1;

    fact[n] = n * factorial(fact, n - 1);
    return fact[n];
}

int kthPermutationSequence(int n, int k)
{
    k--;
    vector<int> fact(n + 1, 1);
    factorial(fact, n);

    int ans = 0;

    vector<int> v(n, 0);
    for (int i = n; i >= 1; i--)
    {
        v[n - i] = k / fact[i-1];
        k %= fact[i-1];
    }

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int count = 0;
        while (j <= v[i])
        {
            if (vis[count] == 0)
                j++;

            count++;
        }
        vis[count - 1] = 1;

        ans *= 10;
        ans += count;
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = kthPermutationSequence(n, k);
    cout << ans;

    return 0;
}