#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
  return (x > y ? x : y);
}

int knapsack(vector<int> values, vector<int> weights, double capacity, int nums)
{
  // base case
  if (nums == 0 || capacity == 0)
  {
    return 0;
  }

  // rejected case
  if (capacity < weights[nums - 1])
  {
    return knapsack(values, weights, capacity, nums - 1);
  }

  int rejected = knapsack(values, weights, capacity, nums - 1);
  int accepted = values[nums - 1] + knapsack(values, weights, capacity - weights[nums - 1], nums - 1);
  return max(rejected, accepted);
}

int knapsack_iterative(vector<int> values, vector<int> weights, double capacity, int nums)
{
  vector<vector<int>> dp(nums, vector<int>(capacity + 1));

  for (int i = 0; i <= nums; i++)
  {
    for (int w = 0; w <= capacity; w++)
    {
      if (i == 0 || w == 0)
      {
        dp[i][w] = 0;
      }
      else if (weights[i - 1] > capacity)
      {
        // rejected
        dp[i][w] = dp[i - 1][w];
      }
      else
      {
        int rejected = dp[i - 1][w];
        int accepted = values[i - 1] + dp[i - 1][w - weights[i - 1]];
        dp[i][w] = max(rejected, accepted);
      }
    }
  }
  return dp[nums][capacity];
}

int main()
{
  int size, value, weight, capacity;
  vector<int> values;
  vector<int> weights;
  cout << "Enter the capacity of the knapsack : ";
  cin >> capacity;
  cout << "Enter the number of items : ";
  cin >> size;
  for (int i = 0; i < size; i++)
  {
    cout << "enter the value of " << i + 1 << " th item : ";
    cin >> value;
    values.push_back(value);
    cout << "enter the weight of " << i + 1 << " th item : ";
    cin >> weight;
    weights.push_back(weight);
  }

  cout << "total value of goods stolen is : " << knapsack_iterative(values, weights, capacity, size);
}