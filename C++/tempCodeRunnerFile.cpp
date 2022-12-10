#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int> &a, vector<int> &b)
{
  if (a[0] == b[0])
    return a[1] < b[1];

  return a[0] < b[0];
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> a = {{7, 0}, {4, 4}, {7, 2}, {5, 0}, {6, 1}, {5, 4}, {8, 0}};
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> a[i][0];
  //   cin >> a[i][1];
  // }

  // {{7, 0}, {4, 4}, {7, 2}, {5, 0}, {6, 1}, {5, 4}, {8, 0}}
  sort(a.begin(), a.end(), comp);

  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < a[i].size(); j++)
    {
      cout << a[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}

// Output
// 5 4
// 4 4
// 7 2
// 6 1
// 8 0
// 7 0
// 5 0