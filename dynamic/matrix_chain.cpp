#include <bits/stdc++.h>
using namespace std;

#define dp_size 25

int matrixchain(int i, int j, int dp[dp_size][dp_size], int d[])
{
  if (i == j)
  {
    return 0;
  }

  if (dp[i][j] != -1)
  {
    return dp[i][j];
  }

  // calculatig the minimum value of these
  dp[i][j] = INT_MAX;
  for (int k = i; k < j; k++)
  {
    int temp = matrixchain(i, k, dp, d) + matrixchain(k + 1, j, dp, d) + d[i - 1] * d[k] * d[j];
    if (dp[i][j] > temp)
    {
      dp[i][j] = temp;
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
  cout << "maximum number of multiplication is : " << matrixchain(1, n - 1, dp, d);
}