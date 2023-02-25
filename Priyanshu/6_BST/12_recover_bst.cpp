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
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }

    // Like inorder, we call on left and right , do some manipulation over them
    calcPointers(root->left, first, mid, last, prev);

    // Checking inorder voilating the inorder or not
    // if yes, then which time
    if (*prev && root->data < (*prev)->data)
    {
        // For 1st time voilating
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root; // will only come for case1 becauz for adjacent(case2) property will never be voilated 2nd time
        }
    }
    *prev = root; // For right subtree
    calcPointers(root->right, first, mid, last, prev);
}
void restoreBST(Node *root)
{
    Node *first, *mid, *last;
    Node *prev; // It will be used as temp

    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    // Case 1 - isn't first and last are not null
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }

    // Case 2 - isn't 1st and mid not null
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorder(root);
    restoreBST(root);
    cout<<endl;
    inorder(root);
    return 0;
}