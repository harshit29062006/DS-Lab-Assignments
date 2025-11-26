/* 4. Write a program to determine whether a given binary tree is a BST or not*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
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

bool isValidBSTUtil(TreeNode* root, long minVal, long maxVal){
    if(root == NULL) return true;

    if(root->data <= minVal || root->data >= maxVal)
        return false;

    return isValidBSTUtil(root->left, minVal, root->data) &&
           isValidBSTUtil(root->right, root->data, maxVal);
}

bool isValidBST(TreeNode* root){
    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}
