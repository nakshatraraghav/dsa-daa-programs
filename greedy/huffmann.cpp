#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  char letter;
  int frequency;

  node *left;
  node *right;

  node(char letter, int frequency)
  {
    this->letter = letter;
    this->frequency = frequency;
  }
};

// c++ shit from this point
// overload the function call operator to make a min heap priority queue

struct compare
{
  bool operator()(node *left, node *right)
  {
    return (left->frequency > right->frequency);
  }
};

void printCodes(node *root, string s)
{
  if (root != NULL)
  {
    if (root->letter != '*')
    {
      cout << root->letter << " -> " << s << endl;
    }
    else
    {
      // not reached root node
      printCodes(root->left, s + '0');
      printCodes(root->right, s + '1');
    }
  }
}

void huffmann(vector<char> letters, vector<int> frequencies, int nums)
{
  priority_queue<node *, vector<node *>, compare> pq;
  for (int i = 0; i < nums; i++)
  {
    pq.push(new node(letters[i], frequencies[i]));
  }
  node *lchild, *rchild;

  while (pq.size() != 1)
  {
    lchild = pq.top();
    pq.pop();
    rchild = pq.top();
    pq.pop();

    node *temp = new node('*', lchild->frequency + rchild->frequency);
    temp->left = lchild;
    temp->right = rchild;

    pq.push(temp);
  }
  printCodes(pq.top(), " ");
  // after this is done the a tree would be constructed finally
}

void run()
{
  char letter;
  int nums, frequency;
  vector<char> letters;
  vector<int> frequencies;
  cout << "Enter the number of characters : ";
  cin >> nums;
  for (int i = 0; i < nums; i++)
  {
    cout << "Enter the " << i + 1 << " th character : ";
    cin >> letter;
    letters.push_back(letter);
    cout << "Enter " << letter << "'s frequency :";
    cin >> frequency;
    frequencies.push_back(frequency);
  }

  huffmann(letters, frequencies, nums);
}

int main()
{
  run();
  return 0;
}