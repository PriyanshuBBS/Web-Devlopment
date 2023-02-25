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

struct Info
{
    int size;
    int max;
    int min;
    int ans; // Size of largest BST
    bool isBST;
};

Info largest_bst(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    // For leaf nodes
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    // Applying for left and right subtree
    Info leftInfo = largest_bst(root->left);
    Info rightInfo = largest_bst(root->right);

    // For current level/node
    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    // 1st 2 conditions are for checking whether the left and right are bst
    // last 2 are for whether the current node is forming the bst (left have less value & right have greater)
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        // update the current node acc to bst
        curr.min = min(leftInfo.min, max(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size; // Since curr is forming bst
        curr.isBST = true;
        return curr;
    }

    // If bst is not forming at curr
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout<<"Largest BST "<< largest_bst(root).ans<<endl;
    return 0;
}