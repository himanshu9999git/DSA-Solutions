#include <bits/stdc++.h>
using namespace std;

vector<int> grayCode(int n)
{
    if (n == 1)
    {
        vector<int> temp;
        temp.push_back(0);
        temp.push_back(1);

        return temp;
    }

    vector<int> lres = grayCode(n - 1);
    vector<int> cres;
    for (int i = 0; i < lres.size(); i++)
    {
        cres.push_back(lres[i]);
    }

    for (int i = lres.size() - 1; i >= 0; i--)
    {
        cres.push_back((1 << (n - 1)) | (lres[i]));
    }
    return cres;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ans = grayCode(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}