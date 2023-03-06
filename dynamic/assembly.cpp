#include <bits/stdc++.h>
using namespace std;

#define STATIONS 5

int min(int x, int y)
{
  return (x < y ? x : y);
}

void assembly(int processing[][STATIONS], int transport[][STATIONS], int path[][STATIONS], int entry[], int exit[])
{
  int first_line[STATIONS], second_line[STATIONS];
  first_line[0] = entry[0] + processing[0][0];
  second_line[0] = entry[0] + processing[1][0];

  // now for each station we need to consider 2 possibilites
  // change to next assembly line or stay on the same on
  // whichever results in least processing cost is the one we will take

  int same_line, change_line;

  for (int i = 1; i < STATIONS; i++)
  {
    // for assembly line #1
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

    // for assembly line #2
    same_line = second_line[i - 1] + processing[1][i];
    change_line = first_line[i - 1] + transport[0][i] + processing[0][i];
    second_line[i] = min(same_line, change_line);
    if (same_line < change_line)
    {
      second_line[i] = same_line;
      path[1][i - 1] = 1;
    }
    else
    {
      second_line[i] = change_line;
      path[1][i - 1] = 2;
    }
  }
  if (first_line[STATIONS - 1] + exit[0] < second_line[STATIONS - 1] + exit[1])
  {
    cout << "total cost is : " << first_line[STATIONS - 1] << "\npath selected is " << endl;
    for (int i = 0; i < STATIONS - 1; i++)
    {
      cout << path[0][i] << " ";
    }
  }
  else
  {
    cout << "total cost is : " << second_line[STATIONS - 1] << "\npath selected is " << endl;
    for (int i = 0; i < STATIONS - 1; i++)
    {
      cout << path[1][i] << " ";
    }
  }
}

// close enough i guess

int main()
{
  int processing[][STATIONS] = {{8, 10, 4, 5, 9}, {9, 6, 7, 5, 6}};
  int transport[][STATIONS] = {{0, 2, 3, 1, 3}, {0, 2, 1, 2, 2}};
  int entry[] = {3, 5};
  int exit[] = {2, 1};
  int path[STATIONS][STATIONS];
  assembly(processing, transport, path, entry, exit);

  return 0;
}