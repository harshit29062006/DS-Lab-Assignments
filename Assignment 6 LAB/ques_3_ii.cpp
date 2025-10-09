/*3. Write a program to find size of
ii. Circular Linked List.*/

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

void sizeOfCLL(Node* head){
    if(head == NULL){
        cout << "Circular Linkded List is Empty!";
    }

    Node* temp = head;
    int count = 0;
    do{
        count++;
        temp = temp->next;
    }while(temp != head);

    cout << "Size of the Circular Linked List is: " << count;

}
int main(){
    vector<int> arr = {20, 100, 80, 40, 60};
    Node* head = convertArr2LL(arr);
    sizeOfCLL(head);
}
