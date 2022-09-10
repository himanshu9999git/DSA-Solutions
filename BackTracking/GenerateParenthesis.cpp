#include <bits/stdc++.h>
using namespace std;

void pts(vector<string> &v, string &s, int op, int cl, int n)
{
    if (s.length() == 2 * n)
        v.push_back(s);

    if (s.length() < 2 * n)
    {
        if (op > 0)
        {
            s.push_back('(');
            pts(v, s, op - 1, cl, n);
            s.pop_back();
        }

        if (cl > op)
        {
            s.push_back(')');
            pts(v, s, op, cl - 1, n);
            s.pop_back();
        }
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> v;
    string s = "";
    pts(v, s, n, n, n);

    return v;
}

int main()
{
    int n;
    cin >> n;

    vector<string> v;
    v = generateParenthesis(n);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}