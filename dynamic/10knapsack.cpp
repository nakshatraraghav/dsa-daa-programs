#include <bits/stdc++.h>
using namespace std;

#define DP_SIZE 25

int max(int x, int y)
{
  return (x > y ? x : y);
}

int knapsack(int values[], int weights[], int capacity, int i, int dp[DP_SIZE][DP_SIZE])
{
  if (i == 0 || capacity == 0)
  {
    return 0;
  }

  // in the dp array case
  if (dp[i][capacity] != -1)
  {
    return dp[i][capacity];
  }

  // rejected case
  if (weights[i - 1] > capacity)
  {
    dp[i][capacity] = knapsack(values, weights, capacity, i - 1, dp);
    return dp[i][capacity];
  }

  int rejected = knapsack(values, weights, capacity, i - 1, dp);
  int accepted = values[i - 1] + knapsack(values, weights, capacity - weights[i - 1], i - 1, dp);
  dp[i][capacity] = max(rejected, accepted);
  return dp[i][capacity];
}

int main()
{
  int size, value, weight, capacity;
  int values[25], weights[25];
  int dp[DP_SIZE][DP_SIZE];
  memset(dp, -1, DP_SIZE);
  cout << "Enter the capacity of the knapsack : ";
  cin >> capacity;
  cout << "Enter the number of items : ";
  cin >> size;
  for (int i = 0; i < size; i++)
  {
    cout << "enter the value of " << i + 1 << " th item : ";
    cin >> values[i];
    cout << "enter the weight of " << i + 1 << " th item : ";
    cin >> weights[i];
  }

  cout << "total value of goods stolen is : " << knapsack(values, weights, capacity, size, dp);
}