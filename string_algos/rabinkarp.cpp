#include <bits/stdc++.h>
#define prime 13
using namespace std;

int solve(string x, string y)
{
  int slen = x.length(), plen = y.length();
  int sh = 0, ph = 0, h = 1, maxchar = 10;
  int flag = 0, count = 0;
  // first let us calcluate the maxchar ^ (plen - 1) value

  for (int i = 0; i < plen - 1; i++)
  {
    h = (h * maxchar) % prime;
  }

  // now calculate the hash value of the first part of string and the hash for the pattern
  for (int i = 0; i < plen; i++)
  {
    sh = (sh * maxchar + x[i]) % prime;
    ph = (ph * maxchar + y[i]) % prime;
  }

  for (int i = 0; i < slen - plen; i++)
  {
    if (sh == ph)
    {
      flag = 0;
      count = 0;

      for (int j = 0; j < plen; j++)
      {
        if (x[i + j] == y[j])
        {
          flag = 1;
          count++;
        }
        else
        {
          break;
        }
      }
      if (count == plen)
      {
        cout << "pattern found at index " << i << endl;
      }
    }
    sh = ((sh - x[i] * h) * maxchar + x[i + plen]) % prime;
    while (sh < 0)
    {
      sh += prime;
    }
  }
  if (flag == 0)
  {
    cout << "pattern not found";
  }
  return count;
}

int main()
{
  string s = "ABCCDDAEFGCDDF";
  string p = "CDD";
  solve(s, p);
}