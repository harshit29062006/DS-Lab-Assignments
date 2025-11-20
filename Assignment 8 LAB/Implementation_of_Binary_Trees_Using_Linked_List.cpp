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
Node* insertNode(){
    int val;
    cout << "Enter the data of the node: ";
    cin >> val;

    if(val == -1){
        return NULL;
    }

    Node* root = new Node(val);

    cout << "Data at left of " << val << endl;
    root->left = insertNode();

    cout << "Data at right of " << val << endl;
    root->right = insertNode();

    return root;
}
int main(){
    Node* root = insertNode();

    return 0;
}
