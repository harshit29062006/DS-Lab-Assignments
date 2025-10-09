/*Find the intersection node of two singly linked lists that merge into a Y-shaped structure.
The lists may vary in length and have distinct nodes at the beginning, but from the point of
intersection onward, they share the same sequence of nodes. The task is to identify the first
common node where the two lists converge. If the two linked lists have no intersection at all,
return null. */

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* findIntersection(Node* firstHead, Node* secondHead){
    if(firstHead == NULL || secondHead == NULL) return NULL;
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;

        if(temp1 == NULL) temp1 = secondHead;
        if(temp2 == NULL) temp2 = firstHead;
    }
    return temp1;
}
