#include<bits/stdc++.h>
using namespace std;

vector<int> maxSubarray(vector<int> arr) {
        int maxsum = 0;
        int cursum = 0;
        int maxint = INT32_MIN;
        int count = 0;
        vector <int> max(2);
        
        for (int i=0; i<arr.size(); i++) 
        {   
            if(arr[i]>maxint)
            maxint = arr[i];
            
            cursum = cursum + arr[i];
            if (cursum>maxsum) 
            {
                maxsum = cursum;
                count++;
            }
            if (cursum < 0)
            cursum = 0;
            
        }
        
        sort(arr.begin(),arr.end());
        int sum = 0;
        int j=0;
        while(arr[j]<0)
        j++;
        
        for (int i=j; i<arr.size(); i++) 
        sum += arr[i];
        
        if(count)
        {
            max[0] = maxsum;
            max[1] = sum;
        }
        else
        {
            max[0] = maxint;
            max[1] = maxint;
        }
        
        return max;
}

int main()
{
    int n;
    cin>>n;

    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    vector <int> result(2);
    result = maxSubarray(arr);
    
    cout<<result[0]<<" "<<result[1];
    return 0;
}