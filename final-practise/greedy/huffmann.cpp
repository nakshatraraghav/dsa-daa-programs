// Huffmann coding is a variable length encoding algorithm
// it works by assigning least number of characters to the
// most occurent alphabet
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

struct compare
{
  bool operator()(node *left, node *right)
  {
    return (left->frequency > right->frequency);
  }
};

void printCode(node *root, string code)
{
  if (root != NULL)
  {
    if (root->letter != '*')
    {
      // not a leaf node since leaf nodes dont have * in as their character value
      cout << "encoding of : " << root->letter << " is : " << code << endl;
    }
    else
    {
      printCode(root->left, code + "0");
      printCode(root->right, code + "1");
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

  // now the priority queue has been created now build the tree
  node *lchild, *rchild;

  while (pq.size() != 1)
  {
    lchild = pq.top();
    pq.pop();
    rchild = pq.top();
    pq.pop();

    node *new_node = new node('*', lchild->frequency + rchild->frequency);
    new_node->left = lchild;
    new_node->right = rchild;

    pq.push(new_node);
  }

  // print the code here
  printCode(pq.top(), " ");
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