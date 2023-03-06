// #include <bits/stdc++.h>
// #define prime 13
// using namespace std;
// // function to find the pattern in effective way/
// int main()
// {
//           // ABC
//   int plen = p.length();
//   int slen = s.length();
//   int ph = 0, sh = 0, h = 1, maxchar = 10;
//   // we assume that the string and the pattern will contain only 10 different
//   // characters from A to J
//   for (int i = 0; i < plen - 1; i++)
//   {
//     h = (h * maxchar) % prime; // to calculate pow(maxchar,plen-1)%prime
//   }
//   for (int i = 0; i < plen; i++)
//   {
//     ph = (ph * maxchar + p[i] - 65 + 1) % prime; // to calculate hash value of the pattern
//     sh = (sh * maxchar + s[i] - 65 + 1) % prime; // to calculate hash value of the first window
//   }
//   cout << "hash value of the pattern" << p << " is " << ph << endl;
//   cout << "hash value of the window " << s.substr(0, plen) << " is " << sh << endl;
//   for (int i = 0; i <= slen - plen; i++)
//   {
//     if (ph == sh)
//     {
//       int flag = 0, count = 0;
//       for (int j = 0; j < plen; j++)
//       {
//         if (s[i + j] == p[j])
//         {
//           flag = 1;
//           count++;
//         }
//         else
//           break;
//       }
//       if (count == plen)
//       {
//         cout << "Pattern occurs at index: " << i << endl;
//         // continue;
//       }
//     }
//     // int nextchar=i+1;
//     if (i < slen - plen) // if the string contains more characters to be compared
//     {
//       sh = ((sh - s[i] * h) * maxchar + (s[i + plen] - 65 + 1)) % prime;
//       while (sh < 0)
//         sh += prime;
//       cout << "hash value of the window" << s.substr(i + 1, plen) << " is " << sh << endl;
//     }
//   } // end of for
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define prime 13

int solve(string x, string y)
{
  int slen = x.length(), plen = y.length();
  int sh = 0, ph = 0, h = 1, maxchar = 10;
  int flag = 0, count = 0;
  for (int i = 0; i < plen - 1; i++)
  {
    h = (h * maxchar) % prime;
  }
  cout << "value of h : " << h << "\n";
  // calculating the maxchar^(plen - 1) value

  for (int i = 0; i < plen; i++)
  {
    sh = (sh * maxchar + x[i]) % prime;
    ph = (ph * maxchar + y[i]) % prime;
  }
  cout << "string hash value " << sh << endl;
  cout << "pattern hash value" << ph << endl;
  // initial hash value of the pattern and window in string

  for (int i = 0; i < slen - plen; i++)
  {
    if (sh == ph)
    {
      flag = 0, count = 0;
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
    cout << "window hash value : " << sh << endl;
  }
  return count;
}

int main()
{
  string s = "ABCCDDAEFGCDDF";
  string p = "CDD";
  solve(s, p);
}