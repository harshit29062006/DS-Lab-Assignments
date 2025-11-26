/*1. Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using recursive approach.*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    } 
};
void preorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->data;
    inorder(root->left);
    inorder(root->right);
}

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void postorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data;
}

