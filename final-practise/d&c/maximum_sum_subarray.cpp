#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
  return (x > y ? x : y);
}

int crosssum(vector<int> nums, int low, int mid, int high)
{
  int left = INT_MIN, right = INT_MIN, sum = 0;
  for (int i = mid; i >= 0; i--)
  {
    sum += nums[i];
    if (sum > left)
    {
      left = sum;
    }
  }
  sum = 0;
  for (int i = mid + 1; i <= high; i++)
  {
    sum += nums[i];
    if (sum > right)
    {
      right = sum;
    }
  }
  return (left + right);
}

int maxsum(vector<int> nums, int low, int high)
{
  if (low == high)
  {
    return 0;
  }

  int mid = (low + high) / 2;
  int temp = max(maxsum(nums, low, mid), maxsum(nums, mid + 1, high));
  return max(crosssum(nums, low, mid, high), temp);
}

int main()
{
  int size;
  vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << "maximum subarray sum is : " << maxsum(array, 0, 8);
  return 0;
}