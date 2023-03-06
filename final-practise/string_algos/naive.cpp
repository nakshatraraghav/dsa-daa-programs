#include <bits/stdc++.h>
using namespace std;

void solve(string x, string y)
{
  int slen = x.length(), plen = y.length();
  int flag = 0;

  for (int i = 0; i < slen - plen; i++)
  {
    int j = 0;
    while (j <= plen && x[i + j] == y[j])
    {
      j++;
      flag = 1;
    }

    if (j == plen)
    {
      cout << "string found at index : " << i << endl;
    }
  }
  if (flag == 0)
  {
    cout << "pattern not found in the string";
  }
}

int main()
{
  string str, pat;
  cout << "Enter the first string : ";
  cin >> str;
  cout << "Enter the second string : ";
  cin >> pat;
  solve(str, pat);
  return 0;
}
