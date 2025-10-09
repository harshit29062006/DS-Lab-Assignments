/*1. Develop a menu driven program for the following operations of on a Circular Linked List.
(a) Insertion anywhere in the linked list (As a first node, as a last node, and
after/before a specific node).
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
deleted may appear as a head node, last node or a node in between.
(c) Search for a node.*/


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
    mover->next = head;
    return head;
}

void print(Node *head){
    if(!head){
        cout << "List is Empty!";
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << endl;
}

Node *insertHead(Node *head, int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode;
    
}

Node *insertTail(Node *head, int val){
    Node* newNode = new Node(val);
    if (head == NULL){
        newNode->next = newNode;
        return newNode;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* insertPosition(Node* head, int el, int val, bool insertAfter){
    if(head == NULL){
        cout << "List is empty!";
        return;
    }

    Node* temp = head;
    do{
        if(temp->data == val){
            Node* newNode = new Node(el);
            if(insertAfter){
                newNode->next = temp->next;
                temp->next = newNode;
                return head;
            } 
            else{
                Node* prev = head;
                while(prev->next != temp){
                    prev = prev->next;
                }
                newNode->next = temp;
                prev->next = newNode;
                if(temp == head)
                    return newNode;
                else
                    return head;
            }
        }
        temp = temp->next;
    } while(temp != head);

    cout << "Value " << val << " not found.\n";
    return head;
}

Node* removeNode(Node* head, int val) {
    if(head == NULL){
        cout << "List is empty!\n";
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;

    if(head->data == val && head->next == head){
        delete head;
        return NULL;
    }

    do {
        if(curr->data == val){
            if(curr == head){
                Node* last = head;
                while (last->next != head)
                    last = last->next;
                last->next = head->next;
                Node* newHead = head->next;
                delete head;
                return newHead;
            } 
            else{
                prev->next = curr->next;
                delete curr;
                return head;
            }
        }
        prev = curr;
        curr = curr->next;
    }while(curr != head);

    cout << "Value " << val << " not found in list.\n";
    return head;
}

int search(Node* head, int val) {
    if(head == NULL) 
        return -1;
    Node* temp = head;
    int pos = 1;
    do{
        if(temp->data == val)
            return pos;
        temp = temp->next;
        pos++;
    }while(temp != head);
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    int x;

    do{
        cout << "1. Insertion at the beginning.\n";
        cout << "2. Insertion at the end.\n";
        cout << "3. Insertion in between (before or after a node having a specific value, say 'Insert anew Node 35 before/after the Node 30').\n";
        cout << "4. Deletion of the node of a given value.\n";
        cout << "5. Search for a node and display its position from head.\n";

        cout << "Enter the number of program you want to execute: ";
        cin >> x;

        switch (x){

        case 1:
            int val1;
            cout << "Enter the value you want to insert at the beginning: ";
            cin >> val1;
            head = insertHead(head, val1);
            break;

        case 2:
            int val2;
            cout << "Enter the value you want to insert at the end: ";
            cin >> val2;
            head = insertTail(head, val2);
            break;

        case 3:
            int val3, pos;
            cout << "Enter the value you want to insert and the element value before which you want to insert: ";
            cin >> val3 >> pos;
            head = insertPosition(head, val3, pos, 0);
            break;

        case 4:
            int val4;
            cout << " Enter the value that you want to delete: ";
            cin >> val4;
            head = removeNode(head, val4);
            break;

        case 5:
            int val5;
            cout << " Enter the value that you want to check: ";
            cin >> val5;
            cout << search(head, val5);
            break;

        default:
            cout << "Enter a valid number!!!";
        }
    }while(x != 0);
    return 0;
}

