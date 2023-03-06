#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<int> selected)
{
  for (int i = 0; i < selected.size(); i++)
  {
    cout << selected[i] << " ";
  }
  cout << endl;
}

void solve(vector<int> nums, vector<int> selected, int target, int sum)
{
  if (target < sum)
  {
    return;
  }

  if (target == sum)
  {
    printSolution(selected);
    return;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    sum += selected[i];
    selected[i] = 1;
    solve(nums, selected, target - selected[i], sum);
    selected[i] = 0;
    sum -= selected[i];
  }
  return;
}

int main()
{
  int size = 6, target = 30;
  vector<int> nums = {5, 10, 12, 13, 15, 18};
  vector<int> selected;
  solve(nums, selected, target, 0);
}