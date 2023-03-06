#include <bits/stdc++.h>
using namespace std;
void calcLPS(string p, int LPS[])
{
  LPS[0] = 0;
  int i = 0, j = 1;
  while (j < p.length())
  {
    if (p[i] == p[j])
    {
      LPS[j] = i + 1;
      i++;
      j++;
    }
    else
    {
      if (i == 0)
      {
        LPS[j] = 0;
        j++;
      }
      else
      {
        i = LPS[i - 1];
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
  int LPS[plen];
  calcLPS(p, LPS); // to build the LPS table
  int i = 0, j = 0;
  while (i < slen)
  {
    if (p[j] == s[i])
    {
      i++;
      j++;
    } // If there is a match, proceed to check the remaining characters
    if (j == plen)
    {
      cout << i - plen << ' '; // to print the index of the string where the pattern matches
      j = LPS[j - 1];
    }
    else if (i < slen && p[j] != s[i])
    {
      if (j == 0)
        i++;
      else
        j = LPS[j - 1]; // if there is a mismatch after a few matched characters,
    }                   // proceed to check only from the LPS of the previously
  }                     // matched character
}

// #include <bits/stdc++.h>
// using namespace std;

// void calculatelps(string pattern, vector<int> lps)
// {
//   int i = 0, j = 1;
//   lps[0] = 0;
//   while (j < pattern.length())
//   {
//     if (pattern[i] == pattern[j])
//     {
//       lps[j] = i + 1;
//       i++;
//       j++;
//     }
//     else
//     {
//       if (i == 0)
//       {
//         lps[j] = 0;
//         j++;
//         // because you cant go i - 1 in this case since idx -1 doesnt exit
//       }
//       else
//       {
//         i = lps[i - 1];
//       }
//     }
//   }
// }

// void sovle(string str, string pat)
// {
//   int slen = str.length(), plen = pat.length();
//   vector<int> lps(plen);
//   calculatelps(pat, lps);
//   int i = 0, j = 0;
//   while (i < slen)
//   {
//     if (str[i] == pat[j])
//     {
//       i++;
//       j++;
//     }
//     if (j == plen)
//     {
//       cout << "string found at : " << i - plen;
//       j = lps[j - 1];
//     }
//     else if (i < slen && pat[j] != str[i])
//     {
//       if (j == 0)
//       {
//         i++;
//       }
//       else
//       {
//         j = lps[j - 1];
//       }
//     }
//   }
// }

// int main()
// {
//   string s = "aaebcaaeaaebcaadaa"; //"ababcdabcb";
//   string p = "aaebcaadaa";
//   sovle(s, p);
// }