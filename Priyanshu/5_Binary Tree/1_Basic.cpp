#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    /*     1
       2      3       */

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    /*      1
          2     3
       5    4   */
    root->left->right = new Node(4);
    root->left->left = new Node(5);

    return 0;
}