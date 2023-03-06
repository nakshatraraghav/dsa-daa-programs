#include <bits/stdc++.h>
using namespace std;

#define STATIONS 5

int min(int x, int y)
{
  return (x < y ? x : y);
}

void assembly(int processing[STATIONS][STATIONS], int transport[STATIONS][STATIONS], int entry[], int exit[])
{
  int path[STATIONS][STATIONS];
  int first_line[STATIONS], second_line[STATIONS];
  int same_line = 0, change_line = 0;

  first_line[0] = entry[0] + processing[0][0];
  second_line[0] = entry[1] + processing[1][0];

  for (int i = 1; i < STATIONS; i++)
  {
    same_line = first_line[i - 1] + processing[0][i];
    change_line = second_line[i - 1] + transport[1][i] + processing[0][i];
    if (same_line < change_line)
    {
      first_line[i] = same_line;
      path[0][i - 1] = 1;
    }
    else
    {
      first_line[i] = change_line;
      path[0][i - 1] = 2;
    }

    same_line = second_line[i - 1] + processing[1][i];
    change_line = first_line[i - 1] + transport[0][i] + processing[0][i];

    if (same_line < change_line)
    {
      second_line[i] = same_line;
      path[1][i - 1] = 2;
    }
    else
    {
      second_line[i] = change_line;
      path[1][i - 1] = 1;
    }
  }

  cout << "total minimum manifacturing cost is  \n";
  if (first_line[STATIONS - 1] + exit[0] < second_line[STATIONS - 1] + exit[1])
  {
    cout << first_line[STATIONS - 1] << endl;
    cout << "path taken is : ";
    for (int i = 0; i < STATIONS; i++)
    {
      cout << path[0][i] << "-> ";
    }
    cout << endl;
  }
  else
  {
    cout << second_line[STATIONS - 1] << endl;
    cout << "path taken is : ";
    for (int i = 0; i < STATIONS; i++)
    {
      cout << path[1][i] << "-> ";
    }
    cout << endl;
  }
}

// void assembly(int processing[STATIONS][STATIONS], int transportation[STATIONS][STATIONS], int entry[], int exit[])
// {
//   int first_line[STATIONS], second_line[STATIONS], same_line, change_line;
//   int path[STATIONS][STATIONS];
//   first_line[0] = entry[0] + processing[0][0];
//   second_line[0] = entry[1] + processing[1][0];

//   for (int i = 1; i < STATIONS; i++)
//   {
//     same_line = first_line[i - 1] + processing[0][i];
//     change_line = second_line[i - 1] + transportation[1][i] + processing[0][i];
//     if (same_line < change_line)
//     {
//       first_line[i] = same_line;
//       path[0][i - 1] = 1;
//     }
//     else
//     {
//       first_line[i] = change_line;
//       path[0][i - 1] = 2;
//     }

//     same_line = second_line[i - 1] + processing[1][i];
//     change_line = first_line[i - 1] + transportation[0][i] + processing[1][i];
//     if (same_line < change_line)
//     {
//       second_line[i] = same_line;
//       path[1][i - 1] = 2;
//     }
//     else
//     {
//       second_line[i] = change_line;
//       path[1][i - 1] = 1;
//     }
//   }

//   cout << "total minimum manifacturing cost is  \n";
//   if (first_line[STATIONS] + exit[0] < second_line[STATIONS] + exit[1])
//   {
//     cout << first_line[STATIONS] << endl;
//     cout << "path taken is : ";
//     for (int i = 0; i < STATIONS; i++)
//     {
//       cout << path[0][i] << "-> ";
//     }
//     cout << endl;
//   }
//   else
//   {
//     cout << second_line[STATIONS] << endl;
//     cout << "path taken is : ";
//     for (int i = 0; i < STATIONS; i++)
//     {
//       cout << path[1][i] << "-> ";
//     }
//     cout << endl;
//   }
// }

int main()
{
  int processing[][STATIONS] = {{8, 10, 4, 5, 9}, {9, 6, 7, 5, 6}};
  int transport[][STATIONS] = {{0, 2, 3, 1, 3}, {0, 2, 1, 2, 2}};
  int entry[] = {3, 5};
  int exit[] = {2, 1};
  assembly(processing, transport, entry, exit);

  return 0;
}