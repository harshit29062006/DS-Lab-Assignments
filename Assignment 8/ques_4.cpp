/* 4. Write a program to determine whether a given binary tree is a BST or not*/

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

bool isValidBST(TreeNode* root){
    return isValidBST(root, long.MIN_VALUE, long.MAX_VALUE);
}

bool isValidBST(TreeNode* root, long minVal, long maxVal){
    if(root == NULL) return true;
    if(root->data >= maxVal || root->data <= minVal) return false;
    return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
}
