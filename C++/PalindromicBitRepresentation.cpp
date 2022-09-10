#include <bits/stdc++.h>
using namespace std;

int PBT(int n)
{
    int count = 0;
    int len = 0;

    while (count < n)
    {
        len++;
        count += pow(2, (len - 1) / 2);
    }

    count -= pow(2, (len - 1) / 2);
    count++;

    int offset = n - count;
    vector<int> off((len + 1) / 2, 0);
    vector<int> ans(len, 0);

    int i = 0;
    while (offset > 0)
    {
        off[i] = offset % 2;
        offset /= 2;
        i++;
    }
    reverse(off.begin(), off.end());

    ans[0] = 1;
    for (int i = 0; i < (len + 1) / 2; i++)
        ans[i] += off[i];

    for (int i = 0; i < (len + 1) / 2; i++)
        ans[len - i - 1] = ans[i];

    int res = 0;
    for (int i = 0; i < len; i++)
    {
        res *= 2;
        res += ans[i];
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << PBT(n);
    return 0;
}