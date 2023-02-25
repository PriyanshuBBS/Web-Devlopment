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

void ZigZag(Node *root)
{
    if(root == NULL){
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    bool LeftRight = true;

    currLevel.push(root);

    while (!currLevel.empty())  // The current became empty at end because swap function not allow it to be empty before
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";
            if (LeftRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }

                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }

            // Right to left
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        if (currLevel.empty()) 
        {
            LeftRight = !LeftRight;
            swap(nextLevel, currLevel); 
        }
    }
}

int main()
{
    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);


    ZigZag(root);
    cout<<endl;
    return 0;
}