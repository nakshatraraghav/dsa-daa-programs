#include <bits/stdc++.h>
using namespace std;

int solve(string x, string y)
{
  int slen = x.length(), plen = y.length(), flag = 0;

  for (int i = 0; i <= slen - plen; i++)
  {
    int j = 0;
    while (j < plen && x.at(i + j) == y.at(j))
    {
      j++;
    }

    if (j == plen)
    {
      cout << "Pattern found at " << i << "\n";
      flag++;
    }
  }
  if (flag == 0)
  {
    cout << "pattern not found in the string \n";
  }
  return flag;
}

int main()
{
  string str, pat;
  cout << "Enter the first string : ";
  cin >> str;
  cout << "Enter the second string : ";
  cin >> pat;
  cout << solve(str, pat);
  return 0;
}
