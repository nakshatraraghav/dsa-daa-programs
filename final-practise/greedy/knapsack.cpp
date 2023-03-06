#include <bits/stdc++.h>
using namespace std;

class item
{
public:
  double value;
  double weight;

  item(double value, double weight)
  {
    this->value = value;
    this->weight = weight;
  }
};

bool compare(item x, item y)
{
  return ((x.value / x.weight) > (y.value / y.weight));
}

int knapsack(vector<item> items, int capacity)
{
  double amount = 0;
  sort(items.begin(), items.end(), compare);

  for (int i = 0; i < items.size(); i++)
  {
    if (items[i].weight <= capacity)
    {
      capacity -= items[i].weight;
      amount += items[i].value;
    }
    else
    {
      amount += items[i].value * (capacity / items[i].weight);
      break;
    }
  }
  return amount;
}

int main()
{
  int size;
  double value, weight, capacity;
  vector<item> items;
  cout << "Enter the number of the items : ";
  cin >> size;
  for (int i = 0; i < size; i++)
  {
    cout << "Enter the value of " << i + 1 << " th item : ";
    cin >> value;
    cout << "Enter the wight of " << i + 1 << " th item : ";
    cin >> weight;
    items.push_back(item(value, weight));
  }

  cout << "Enter the capacity of the knapsack : ";
  cin >> capacity;

  cout << "The total stolen goods amount to : " << knapsack(items, capacity);
}