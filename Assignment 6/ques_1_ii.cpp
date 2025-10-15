/*1. Develop a menu driven program for the following operations of on a Doubly Linked List.
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
    Node* next;
    Node* prev;

    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArr2DLL(vector<int>& arr){
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    if (!head){
        cout << "List is Empty!\n";
        return;
    }
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insertHead(Node* head, int val){
    Node* newNode = new Node(val);
    if(!head){
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

Node* insertTail(Node* head, int val){
    Node* newNode = new Node(val);
    if(!head){
        return newNode;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insertPosition(Node* head, int el, int val, bool insertAfter){
    if(!head) {
        cout << "List is empty!\n";
        return head;
    }

    Node* temp = head;
    while (temp != nullptr){
        if(temp->data == val) {
            Node* newNode = new Node(el);
            if(insertAfter){
                Node* nxt = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = nxt;
                if(nxt) nxt->prev = newNode;
                return head;
            } 
            else{
                Node* prv = temp->prev;
                newNode->next = temp;
                newNode->prev = prv;
                temp->prev = newNode;
                if(prv) prv->next = newNode;
                else head = newNode;
                return head;
            }
        }
        temp = temp->next;
    }

    cout << "Value " << val << " not found.\n";
    return head;
}

Node* removeNode(Node* head, int val) {
    if(!head){
        cout << "List is empty!\n";
        return nullptr;
    }

    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == val) {
            if(temp->prev) temp->prev->next = temp->next;
            else head = temp->next;

            if(temp->next) temp->next->prev = temp->prev;

            delete temp;
            return head;
        }
        temp = temp->next;
    }

    cout << "Value " << val << " not found in list.\n";
    return head;
}

int search(Node* head, int val){
    Node* temp = head;
    int pos = 1;
    while(temp != nullptr){
        if(temp->data == val)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2DLL(arr);
    int x;

    do {
        cout << "1. Insertion at the beginning.\n";
        cout << "2. Insertion at the end.\n";
        cout << "3. Insertion before a specific node.\n";
        cout << "4. Deletion of the node of a given value.\n";
        cout << "5. Search for a node and display its position.\n";
        cout << "6. Display list.\n";
        cout << "0. Exit.\n";

        cout << "Enter the number of program you want to execute: ";
        cin >> x;

        switch(x){
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
            cout << "Enter the value to insert and the element value before which you want to insert: ";
            cin >> val3 >> pos;
            head = insertPosition(head, val3, pos, false);
            break;
        

        case 4:
            int val4;
            cout << "Enter the value that you want to delete: ";
            cin >> val4;
            head = removeNode(head, val4);
            break;
        

        case 5:
            int val5;
            cout << "Enter the value that you want to check: ";
            cin >> val5;
            int res = search(head, val5);
            if (res != -1)
                cout << "Value found at position: " << res << endl;
            else
                cout << "Value not found.\n";
            break;
        
        case 6:
            cout << "Current List: ";
            print(head);
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Enter a valid number!!!\n";
        }
    }while(x != 0);

    return 0;
}
