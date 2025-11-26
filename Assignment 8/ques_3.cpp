/* 3. Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
(b) Delete an existing element,
(c) Maximum depth of BST
(d) Minimum depth of  */

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

TreeNode* insertIntoBST(TreeNode* root, int val){
    if(root == NULL) return new TreeNode(val);
    TreeNode* curr = root;
    while(true){
        if(curr->data <= val){
            if(curr->right != NULL) curr = curr->right;
            else{
                curr->right = new TreeNode(val);
                break;
            }
        }
        else{
            if(curr->left != NULL) curr = curr->left;
            else{
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

TreeNode* helper(TreeNode* root){
    if(root->left == NULL){
        return root->right;
    }
    else if(root->right == NULL){
        return root->left;
    }

    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key){
    if(root == NULL) return NULL;

    if(root->data == key){
        return helper(root);
    }

    TreeNode* dummy = root;
    while(root != NULL){
        if(root->data > key){
            if(root->left != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            } 
            else{
                root = root->left;
            }
        }
        else{
            if(root->right != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            }
            else{
                root = root->right;
            }
        }
    }
    return dummy;
}

TreeNode* findLastRight(TreeNode* root){
    if(root->right == NULL){
        return root;
    }
    return findLastRight(root->right);
}



