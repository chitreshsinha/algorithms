//https://www.geeksforgeeks.org/print-left-view-binary-tree/

//#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// A wrapper over leftViewUtil()
void leftView(struct Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     leftView(root);
     cout << endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// A wrapper over leftViewUtil()

void preOrder(Node *root, int level, int *maxLevel) {
    if(root==NULL) {
        return;
    }
    if(*maxLevel < level) {
        *maxLevel = level;
        cout << root->data << " ";
    }
    preOrder(root->left, level+1, maxLevel);
    preOrder(root->right, level+1, maxLevel);
}

void leftView(Node *root)
{
    int maxLevel = 0;
    preOrder(root, 1, &maxLevel);
}

// Example:
// Input:
// 2
// 2
// 1 2 R 1 3 L
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R

// Output:
// 1 3
// 10 20 40

