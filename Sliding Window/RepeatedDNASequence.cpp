// https://leetcode.com/problems/repeated-dna-sequences/submissions/

#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    int n = s.length();
    vector<string> ans;

    if (n <= 10)
        return ans;

    unordered_map<string, int> mp;
    for (int i = 0; i <= n - 10; i++)
    {
        mp[s.substr(i, 10)]++;
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second > 1)
            ans.push_back(i->first);
    }
    return ans;
}

int main()
{

    string s;
    cin >> s;

    vector<string> ans = findRepeatedDnaSequences(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}