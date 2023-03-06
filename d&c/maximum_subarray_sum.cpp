#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
  return (x > y ? x : y);
}

int crossSum(int array[], int low, int mid, int high)
{
  int left = INT_MIN, right = INT_MIN, sum = 0;
  for (int i = mid; i >= low; i--)
  {
    sum += array[i];
    if (sum > left)
    {
      left = sum;
    }
  }
  sum = 0;
  for (int i = mid + 1; i < high; i++)
  {
    sum += array[i];
    if (sum > right)
    {
      right = sum;
    }
  }
  return (left + right);
}

int maxsum(int array[], int low, int high)
{
  if (low == high)
  {
    return 0;
  }

  int mid = (low + high) / 2;
  int temp = max(maxsum(array, low, mid), maxsum(array, mid + 1, high));
  return (temp, crossSum(array, low, mid, high));
}

int main()
{
  int size, array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << "maximum subarray sum is : " << maxsum(array, 0, 8);
  return 0;
}