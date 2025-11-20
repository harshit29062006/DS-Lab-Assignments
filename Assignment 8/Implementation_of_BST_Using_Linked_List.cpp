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
