/*Write a program to check if a linked list is Circular Linked List or not.*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node *convertArr2LL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *convertArr2CLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    mover->next = head;
    return head;
}

bool isCLL(Node* head){
    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == head)
        return true;
    else
        return false;
}
int main(){
    vector<int> arr = {20, 100, 80, 40, 60};
    Node* head1 = convertArr2LL(arr);
    Node* head2 = convertArr2CLL(arr);
    cout << isCLL(head1) << endl;
    cout << isCLL(head2) << endl;
}
