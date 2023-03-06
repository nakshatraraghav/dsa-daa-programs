#include <bits/stdc++.h>
#define prime 13
using namespace std;

int rabinkarp(string str, string pat)
{
  int slen = str.length(), plen = pat.length();
  int string_hash = 0, pattern_hash = 0, h = 1, maxchar = 10;
  int count = 0;
  // maxchar equals the number of characters

  // Step 1: Calculate the (maxchar) ^ (plen - 1);

  for (int i = 0; i < plen - 1; i++)
  {
    h = (h * maxchar) % prime;
  }

  // Step 2: Now calculate the hash value of the pattern and the string upto plen in the string

  for (int i = 0; i < plen; i++)
  {
    string_hash = (string_hash * maxchar + str[i]) % prime;
    pattern_hash = (pattern_hash * maxchar + pat[i]) % prime;
  }

  // Step 3: Start the main loop
  for (int i = 0; i < slen - plen; i++)
  {
    if (string_hash == pattern_hash)
    {
      int j = 0;
      while (j < plen && str[i + j] == pat[j])
      {
        j++;
      }
      if (j == plen)
      {
        cout << "pattern found at index : " << i << endl;
        count++;
      }
    }

    string_hash = ((string_hash - str[i] * h) * maxchar + str[i + plen]) % prime;
    while (string_hash < 0)
    {
      string_hash += prime;
    }
  }
  return count;
}

int main()
{
  string s = "ABCCDDAEFGCDDF";
  string p = "CDD";
  rabinkarp(s, p);
}