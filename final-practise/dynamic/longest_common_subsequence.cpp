#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
  return (x > y ? x : y);
}

int solve(string x, string y, int i, int j)
{
  if (x[i] == '\0' || y[j] == '\0')
  {
    return 0;
  }
  else if (x[i] == y[j])
  {
    return 1 + solve(x, y, i + 1, j + 1);
  }
  else
  {
    return max(solve(x, y, i + 1, j), solve(x, y, i, j + 1));
  }
}

int solve_iterative(string x, string y)
{
  int dp[25][25];
  for (int i = 0; i <= x.length(); i++)
  {
    for (int j = 0; j <= y.length(); j++)
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
  return dp[x.length()][y.length()];
}

int main()
{
  string x, y;
  cout << "enter the first string : ";
  cin >> x;
  cout << "enter the second string : ";
  cin >> y;
  cout << "length of longest common subsequence : " << solve(x, y, 0, 0);
  cout << "length of longest common subsequence iterative : " << solve_iterative(x, y);
}