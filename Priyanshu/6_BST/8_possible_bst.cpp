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

vector<Node *> constructTrees(int start, int end) // Start = 1, end = n
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
    }

    // Constructing the loop for lower levels
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubtrees = constructTrees(start, i - 1); // i-1 because the property of bsr states that left is at i-1
        vector<Node *> rightSubtrees = constructTrees(i + 1, end);

        // Now doing the Catalan work - Combining the left and right subtrees
        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            Node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                Node *right = rightSubtrees[k];
                // Left and Right Nodes are construted by i-1 and i+1, so ith too need
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    vector<Node*> Totaltrees = constructTrees(1, 3);
    for (int i = 0; i < Totaltrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        preorder(Totaltrees[i]);
        cout << endl;
    }
    return 0;
}