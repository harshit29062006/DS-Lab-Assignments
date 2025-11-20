#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data1){
        data = data1;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int val){
    if(root == NULL) return new Node(val);

    if(val < root->data){
        root->left = insertNode(root->left,val);
    }
    else{
        root->right = insertNode(root->right,val);
    }

    return root;
}

int searchElementRecursive(Node* root, int val){
    if(root == NULL) return -1;

    if(val == root->data){
        return root->data;
    }
    else if(val > root->data){
        searchElementRecursive(root->right, val);
    }
    else if(val < root->data){
        searchElementRecursive(root->left, val);
    }
    else{
        return -1;
    }
}

int searchElement(Node* root, int val){
    if(root == NULL) return -1;

    while(root != NULL && root->data != val){
        root = val < root->data ? root->left : root->right;
    }
    return root->data;
}

int inorderSuccessor(Node* root, Node* p){
    if(root == NULL) return -1;

    while()
}



int maxElement(Node* root){
    if(root == NULL) return NULL;

    while(root != NULL){
        root = root->right;
    }

    return root->data;
}
int minElement(Node* root){
    if(root == NULL) return NULL;

    while(root != NULL){
        root = root->left;
    }
    return root->data;
}

int main(){
    Node* head = NULL;
    int val;

    cout << "Enter the values you want to enter: ";

    while(true){
        cin >> val;
        if(val == -1) break;
        head = insertNode(head, val);
    }

    return 0;
}
