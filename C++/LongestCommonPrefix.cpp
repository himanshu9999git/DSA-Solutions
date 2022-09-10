#include<bits/stdc++.h>
using namespace std;

string LCP(vector<string> v)
{
    int n = v.size();
    string a = v[0];
    string s = "";

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        s = a;
        a = "";
        while(j<s.length() && j<v[i].length())
        {
            if(s[j] == v[i][j])
                a.push_back(s[j]);

            else
                break;

            j++;
        }

        if(a.length() == 0)
            break;
    }
    return a;
}

int main()
{
    int n;
    cin>>n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }    

    string ans = LCP(v);
    cout<<ans;

    return 0;
}