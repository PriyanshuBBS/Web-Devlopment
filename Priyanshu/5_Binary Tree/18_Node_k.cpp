// O(n^2) as Height has O(n) and Dia 0(n)

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

void PrintSub(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    PrintSub(root->left, k - 1);
    PrintSub(root->right, k - 1);
}

// The return type is used so that we can return the distance to ancestor
int printNodeK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        PrintSub(root, k);
        return 0;
    }

    int dl = printNodeK(root->left, target, k);
    if (dl != -1) // We didn't found target in left subtree
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            PrintSub(root->right, k - dl - 2); // why -2? 1 for root's left to root and other form root to its right
        }
        return 1 + dl;
    }

    int dr = printNodeK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            PrintSub(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    printNodeK(root, root->left, 1);
    return 0;
}