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

int karatsuba(int x, int y)
{
  if (x < 10 && y < 10)
  {
    return x * y;
  }
  // step 1: first find out the number of digits in max of x or y
  int size = max(digits(x), digits(y));
  // step 2: find the value of n which is ceil(size / 2)
  int n = ceil(size / 2);
  // step 3: now calculate 10 ^ n
  int power = pow(10, n);
  // step 4: now find a, b, c, d values
  int a = floor(x / power);
  int b = floor(x % power);
  int c = floor(y / power);
  int d = floor(y % power);
  // step 5: now find the values s1, s2, s3
  int s1 = karatsuba(a, c);
  int s2 = karatsuba(b, d);
  int s3 = karatsuba(a + b, c + d);
  // step 6: now return the answer
  return s1 * pow(10, 2 * n) + (s3 - s2 - s1) * pow(10, n) + s2;
}

int main()
{
  int x, y;
  cout << "enter the first number : ";
  cin >> x;
  cout << "enter the second number : ";
  cin >> y;
  cout << "the answer is : " << karatsuba(x, y);
  return 0;
}