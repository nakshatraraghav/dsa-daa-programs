#include <bits/stdc++.h>
using namespace std;

int digits(int number)
{
  int count = 0;
  while (number > 0)
  {
    number /= 10;
    count++;
  }
  return count;
}

long long karastuba(int x, int y)
{
  if (x < 10 && y < 10)
  {
    return x * y;
  }

  long long size = max(digits(x), digits(y));
  long long n = ceil(size / 2);
  long long power = pow(10, n);
  long long a = floor(x / power);
  long long b = x % power;
  long long c = floor(y / power);
  long long d = y % power;

  long long s1 = karastuba(a, c);
  long long s2 = karastuba(b, d);
  long long s3 = karastuba(a + b, c + d);

  return s1 * pow(10, 2 * n) + (s3 - s2 - s1) * pow(10, n) + s2;
}

int main()
{
  cout << karastuba(1026732, 732912);
  return 0;
}