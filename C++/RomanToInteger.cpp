#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='M') ans+=1000; 
        else if(s[i]=='D'){
            if(s[i+1]&&s[i+1]=='M') ans-=500;
            else ans+=500;
        }
        else if(s[i]=='C') {
            if(s[i+1]&&(s[i+1]=='D'||s[i+1]=='M')) ans-=100;
            else ans+=100; 
        }
        else if(s[i]=='L') {
            if(s[i+1]&&(s[i+1]=='D'||s[i+1]=='M'||s[i+1]=='C')) ans-=50;
            else ans+=50;
        }
        else if(s[i]=='X'){
            if(s[i+1]&&(s[i+1]=='D'||s[i+1]=='M'||s[i+1]=='C'||s[i+1]=='L')) ans-=10;
            else ans+=10; 
        }
        else if(s[i]=='V') {
            if(s[i+1]&&(s[i+1]!='I'&&s[i+1]!='V')) ans-=5;
            else ans+=5; 
        }
        else{
            if(s[i+1]&&s[i+1]!='I'){
                ans--;
            }
            else ans++;
        }
    }
    return ans;

}

int main()
{
    string s;
    cin >> s;

    int ans = romanToInt(s);
    cout<<ans;

    return 0;
}