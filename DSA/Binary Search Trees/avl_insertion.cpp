#include<bits/stdc++.h>
#include "declaration.h"
using namespace std;

int height(Node* root) {
    if(root == NULL)
        return 0;
    int lh, rh;
    lh = height(root->left);
    rh = height(root->right);
}

Node* insert_node(Node* root, int val) {
    if(root == NULL) {
        Node* root = new Node();
        root->left = root->right = NULL;
        root->data = val;
        return root;
    }
    if(val < root->data) {
        root->left = insert_node(root->left, val);
    }
    else if(val > root->data) {
        root->right = insert_node(root->right, val);
    }
    return root;   
}