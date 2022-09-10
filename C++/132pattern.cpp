#include <bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int> &nums)
{
    int n = nums.size();
    bool flag = false;
    for (int i = n - 1; i >= 2; i++)
    {
        stack<int> s;
        int j = i - 1;
        int mx = nums[i];
        while (j >= 0)
        {
            if (j >= 1)
            {
                if (nums[j] > mx)
                {
                    s.push(nums[j]);
                    mx = s.top();
                }
            }

            if ((nums[i] > nums[j]) && !s.empty())
            {
                flag = true;
                break;
            }
            j--;
        }

        if (flag)
            break;
    }
    return flag;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (find132pattern)
        cout << "TRUE";

    else
        cout << "FALSE";
    return 0;
}