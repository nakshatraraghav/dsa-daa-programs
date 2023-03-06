#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
  return (x > y ? x : y);
}

int lcs(string x, string y, int i, int j)
{
  if (x[i] == '\0' || y[j] == '\0')
  {
    return 0;
  }

  if (x[i] == y[j])
  {
    return 1 + lcs(x, y, i + 1, j + 1);
  }

  return max(lcs(x, y, i + 1, j), lcs(x, y, i, j + 1));
}

int lcs_iterative(string x, string y)
{
  int dp[25][25], m = x.length(), n = y.length();
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      else if (x[i] == y[j])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}

int main()
{
  string x, y;
  cout << "Enter the first string : ";
  cin >> x;
  cout << "Enter the second string : ";
  cin >> y;
  cout << lcs_iterative(x, y);
}
