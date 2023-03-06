#include <bits/stdc++.h>
using namespace std;

#define dp_size 25

// matrix[1, j] = sigma (i <= k < j) min(matrix[i, k] + matrix[k + 1, j] + d(i -1) * d(c) * d(k))

int matrix(int i, int j, int dp[dp_size][dp_size], int d[])
{
  if (i == j)
  {
    return 0;
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  dp[i][j] = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int value = matrix(i, k, dp, d) + matrix(k + 1, j, dp, d) + d[i - 1] * d[k] * d[j];
    if (value < dp[i][j])
    {
      dp[i][j] = value;
    }
  }
  return dp[i][j];
}

int main()
{
  int dp[25][25];
  memset(dp, -1, sizeof dp);
  int d[] = {1, 2, 3, 4};
  int n = sizeof(d) / sizeof(d[0]);
  cout << "maximum number of multiplication is : " << matrix(1, n - 1, dp, d);
}