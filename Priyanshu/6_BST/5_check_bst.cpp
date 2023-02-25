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

bool checkBST(Node *root, Node *min = NULL, Node *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }
    // When recursion called for max / mix (INT MIN/INT MAX) should be there for proper working
    // It is also to check whether the root is valid or not
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }

    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftvalid = checkBST(root->left, min, root);
    bool rightvalid = checkBST(root->right, root, max);
    return leftvalid and rightvalid;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    if (checkBST(root1, NULL, NULL))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }

    Node *root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(8);

    // int max = INT_MAX;
    if (checkBST(root2, NULL, NULL))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }
    return 0;
}