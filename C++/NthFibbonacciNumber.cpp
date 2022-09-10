#include<bits/stdc++.h>
using namespace std;

int fibbonacci(int n)
{
    if(n == 1 || n == 2)
        return n-1;

    return (fibbonacci(n-2)%1000000007 + fibbonacci(n-1)%1000000007);    
}

int main()
{
    int n;
    cin>>n;
    
    cout<<fibbonacci(n);
    return 0;
}