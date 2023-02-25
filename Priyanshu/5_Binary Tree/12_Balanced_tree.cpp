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
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight, rightheight) + 1;
}
bool isbalanced(Node *root)
{
    // If any one of the node is not balanced then whole tree is unbalanced
    if (root == NULL)
    {
        return true;
    }
    if (root->left == false)
    {
        return false;
    }

    if (root->right == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
}

bool isBalanced_Opti(Node *root, int *height)
{

    // If any one of the node is not balanced then whole tree is unbalanced
    if (root == NULL)
    {
        return true;
    }

    int lh = 0;
    int rh = 0;
    if (isBalanced_Opti(root->left, &lh) == false)
    {
        return false;
    }

    if (isBalanced_Opti(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    if (isbalanced(root))
    {
        cout << "Balanced tree\n";
    }
    else
    {
        cout << "Unbalanced\n";
    }

    if (isbalanced(root2))
    {
        cout << "Balanced tree\n";
    }
    else
    {
        cout << "Unbalanced\n";
    }
    return 0;
}