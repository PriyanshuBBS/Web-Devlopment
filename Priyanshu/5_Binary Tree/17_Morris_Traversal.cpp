#include<bits/stdc++.h>
using namespace std;
 
int main(){
    Node* current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
           
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
          
            else {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
    return 0;
}