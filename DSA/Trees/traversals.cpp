#include<bits/stdc++.h>
#include "declaration.cpp"
using namespace std;

// pre order traversal (DFS)
void preOrder(Node* root) {
    if(root) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// in order traversal (DFS)
void inOrder(Node* root) {
    if(root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// post order traversal (DFS)
void postOrder(Node* root) {
    if(root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// level order traversal (BFS)
void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    Node* curr;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if(curr->left) {
            q.push(curr->left);
        }
        if(curr->right) {
            q.push(curr->right);
        }
    }
}

// inorder traversal without recursion
void inOrderIter(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while(curr || !s.empty()) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}


