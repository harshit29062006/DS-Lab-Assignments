/*3. Write a program to find size of
i. Doubly Linked List.*/

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

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
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

void sizeOfDLL(Node* head){
    if(head == NULL){
        cout << "Doubly Linked List is Empty!";
        return;
    }

    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    cout << "Size of the Doubly Linked List is: " << count;
}

int main(){
    vector<int> arr = {20, 100, 80, 40, 60};
    Node* head = convertArr2DLL(arr);
    sizeOfDLL(head);
    return 0;
}
