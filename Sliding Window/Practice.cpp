#include<bits/stdc++.h>
using namespace std;



int main()
{
    vector<int> s= {13,11,1,8,6,7,8,8,6,7,8,9,8};
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<" ";
    }
    
    return 0;
}