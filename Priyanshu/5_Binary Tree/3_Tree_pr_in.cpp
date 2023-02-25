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
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    // ********** Love Babbar Solution **********
    Node *buildTree(int inorder[], int preorder[], int n)
    {
        int preOrderIndex = 0; // A variable to move on Preorder Array
        return solve(inorder, preorder, preOrderIndex, 0, n - 1, n);
    }

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

    Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
    {
        // Base case
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = pre[index];
        index++;
        Node *root = new Node(element); // Creating the start node

        int position = findposition(in, element, n); // Finding the position in Inorder

        // Recursive call
        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);

        return root;
    }
};