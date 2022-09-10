#include<bits/stdc++.h>
using namespace std;



int main()
{
    string A;
    cin>>A;

    int n = A.length();
    vector<string> ans;
    string s= "";
    for(int i=0; i<n; i++)
    {
        s = "";
        while(i<n && A[i] >= 'a' && A[i] <= 'z')
        {
            s.push_back(A[i]);
            i++;
        }
        
        while(i<n && A[i] < 'a' && A[i] > 'z')
            i++;
            
        i--;
            
        ans.push_back(s);
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}