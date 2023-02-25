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

Node *Array_BST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = Array_BST(arr, start, mid - 1);

    root->right = Array_BST(arr, mid + 1, end);
    return root;
}

void preorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    Node *root = Array_BST(arr, 0, 4);
    preorderPrint(root);
    cout << endl;
    return 0;
}