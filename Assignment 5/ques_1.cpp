/* 1. Develop a menu driven program for the following operations on a Singly Linked
List.
(a) Insertion at the beginning.
(b) Insertion at the end.
(c) Insertion in between (before or after a node having a specific value, say 'Insert a
new Node 35 before/after the Node 30').
(d) Deletion from the beginning.
(e) Deletion from the end.
(f) Deletion of a specific node, say 'Delete Node 60').
(g) Search for a node and display its position from head.
(h) Display all the node values.
*/

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

void print(Node *head){
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insertHead(Node *head, int val){
    Node *temp = new Node(val, head);
    return temp;
}

Node *insertTail(Node *head, int val){
    if (head == NULL)
    {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node *insertPosition(Node *head, int el, int val){
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == val)
    {
        return new Node(el, head);
    }
    bool found = false;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next->data == val)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found == false)
    {
        cout << "Value not found in the linked list";
    }
    return head;
}

Node *removeHead(Node *head){
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *removeTail(Node *head){
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteK(Node *head, int k){
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int checkIfPresent(Node *head, int val){
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    int x;

    do
    {
        cout << "1. Insertion at the beginning \n";
        cout << "2. Insertion at the end. \n";
        cout << "3. Insertion in between (before or after a node having a specific value, say 'Insert anew Node 35 before/after the Node 30'). \n";
        cout << "4. Deletion from the beginning. \n";
        cout << "5. Deletion from the end. \n";
        cout << "6. Deletion of a specific node, say 'Delete Node 60'). \n";
        cout << "7. Search for a node and display its position from head. \n";
        cout << "8. Display all the node values \n";

        cout << "Enter the number of program you want to execute: ";
        cin >> x;

        switch (x)
        {

        case 1:
            int val;
            cout << "Enter the value you want to insert at the beginning: ";
            cin >> val;
            head = insertHead(head, val);
            break;

        case 2:
            int val;
            cout << "Enter the value you want to insert at the end: ";
            cin >> val;
            head = insertTail(head, val);
            break;

        case 3:
            int val, pos;
            cout << "Enter the value you want to insert and the element value before which you want to insert: ";
            cin >> val >> pos;
            head = insertPosition(head, val, pos);
            break;

        case 4:
            head = removeHead(head);
            break;

        case 5:
            head = removeTail(head);
            break;

        case 6:
            int del;
            cout << "Enter the number of Node you want to delete: ";
            cin >> del;
            head = deleteK(head, del);
            break;

        case 7:
            cout << checkIfPresent(head, val);
            break;

        case 8:
            print(head);
            break;

        default:
            cout << "Enter a valid number!!!";
        }
    } while (x != 0);

    return 0;
}
