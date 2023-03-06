#include <bits/stdc++.h>
using namespace std;

void calculatelps(string pattern, int lps[])
{
  lps[0] = 0;
  int i = 0, j = 1;
  while (j < pattern.length())
  {
    if (pattern[i] == pattern[j])
    {
      lps[j] = i + 1;
      i++;
      j++;
    }
    else
    {
      if (i == 0)
      {
        lps[i] = 0;
        j++;
      }
      else
      {
        i = lps[i - 1];
      }
    }
  }
}

int main()
{
  string s = "aaebcaaeaaebcaadaa"; //"ababcdabcb";
  string p = "aaebcaadaa";         //"abc";
  int slen = s.length();
  int plen = p.length();
  int lps[plen];
  calculatelps(p, lps);
  int i = 0, j = 0;
  while (i < slen)
  {
    if (s[i] == p[j])
    {
      i++;
      j++;
    }

    if (j == plen)
    {
      cout << "pattern found at : " << i - plen << " ";
      j = lps[j - 1];
    }

    else if (i < slen && s[i] != p[j])
    {
      if (j == 0)
      {
        i++;
      }
      else
      {
        j = lps[j - 1];
      }
    }
  }
}