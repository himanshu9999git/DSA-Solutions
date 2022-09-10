// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveAnswers(string s, int k)
{
    int n = s.length();
    int i = 0;
    int j = 0;
    int count = 0;
    int x = k;

    while (j < n)
    {
        if (s[j] == 'F')
            k--;

        if (k < 0)
        {
            if (s[i] == 'F')
                k++;

            i++;
        }
        j++;

        count = max(count, j - i);
    }

    i = 0;
    j = 0;

    while (j < n)
    {
        if (s[j] == 'T')
            x--;

        if (x < 0)
        {
            if (s[i] == 'T')
                x++;

            i++;
        }
        j++;

        count = max(count, j - i);
    }
    return count;
}

int main()
{

    string s;
    cin >> s;

    int k;
    cin >> k;

    int ans = maxConsecutiveAnswers(s, k);
    cout << ans;

    return 0;
}