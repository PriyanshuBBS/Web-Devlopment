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

void printlevelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    // Pushing for the 0th level
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front(); 
        q.pop();    // This is helping in pushing forward the loop/ emptying the loop
        if (node != NULL) // Checking the front of Queue
        {
            cout << node->data << " ";
            // Inserting the left and right of the Node to queue if not NULL
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);   // Inserting the NULL after each level
        }
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

    printlevelorder(root);
    return 0;
}