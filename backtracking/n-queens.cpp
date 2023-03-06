#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> board, int nums)
{
  for (int i = 0; i < nums; i++)
  {
    for (int j = 0; j < nums; j++)
    {
      if (board[i][j])
      {
        cout << "Q ";
      }
      else
      {
        cout << ". ";
      }
    }
    cout << "\n";
  }
}

bool isSafe(vector<vector<int>> board, int row, int col, int nums)
{
  int orignal_row = row, orignal_col = col;
  // upper diagonal
  while (row >= 0 && col >= 0)
  {
    if (board[row][col])
    {
      return false;
    }
    row--;
    col--;
  }
  row = orignal_row;
  col = orignal_col;
  // same row
  while (col >= 0)
  {
    if (board[row][col])
    {
      return false;
    }
    col--;
  }
  row = orignal_row;
  col = orignal_col;
  // lower diagonal
  while (row < nums && col >= 0)
  {
    if (board[row][col])
    {
      return false;
    }
    row++;
    col--;
  }

  return true;
}

void solve(vector<vector<int>> board, int col, int nums)
{
  // this will be solved when col == nums
  if (col >= nums)
  {
    printSolution(board, nums);
    cout << "\n\n";
    return;
  }

  for (int row = 0; row < nums; row++)
  {
    if (isSafe(board, row, col, nums))
    {
      board[row][col] = 1;
      solve(board, col + 1, nums);
      board[row][col] = 0;
    }
  }
  return;
}

int main()
{
  int nums;
  cout << "Enter the size of the chess board : ";
  cin >> nums;
  vector<vector<int>> board(nums, vector<int>(nums));
  solve(board, 0, nums);
}