// O(n^2) as Height has O(n) and Dia 0(n)

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

int calHeight(Node *root)
{
    if(root == NULL){
        return 0;
    }
    int leftheight = calHeight(root->left);
    int rightheight = calHeight(root->right);
    return max(leftheight,rightheight) + 1;
}


int calDia(Node *root)
{   
    if(root == NULL){
        return 0;   // As dia would be zero 
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int currDia = lHeight + rHeight + 1;

    int lDiameter = calDia(root->left);
    int rDiameter = calDia(root->right); 

    return max(currDia, max(lDiameter,rDiameter));
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

    cout<<calDia(root)<<endl;

    return 0;
}