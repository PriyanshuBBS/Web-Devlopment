#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int findposition(int inorder[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int pos[], int &index, int inorderStart, int inorderEnd, int n)
{
    // Base case
    if (index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pos[index];
    index--;
    Node *root = new Node(element); // Creating the start node

    int position = findposition(in, element, n); // Finding the position in Inorder

    // Recursive call

    root->right = solve(in, pos, index, position + 1, inorderEnd, n);
    root->left = solve(in, pos, index, inorderStart, position - 1, n);
    return root;
}
Node *buildTree(int inorder[], int postorder[], int n)
{
    int postOrderIndex = n - 1;
    return solve(inorder, postorder, postOrderIndex, 0, n - 1, n);
}