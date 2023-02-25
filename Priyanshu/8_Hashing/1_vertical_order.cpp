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

void get_vertical(Node *root, int hdis, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }

    m[hdis].push_back(root->data);

    get_vertical(root->left, hdis - 1, m);
    get_vertical(root->right, hdis + 1, m);
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int, vector<int>> m;
    int hori_dis = 0;

    get_vertical(root, hori_dis, m);

    map<int, vector<int>>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        // Traversing the vertical line having numbers in it
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }
    

    return 0;
}