// 4. Write a program to check if a doubly linked list of characters is palindrome or not.

#include<bits/stdc++.h>
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

Node* convertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

bool isPalindrome(Node* head){
    if(head == NULL){
        return true;
    }

    Node* temp = head;
    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    while(head != tail && tail->next != head){
        if(head->data != tail->data){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;    
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 1};
    Node* head = convertArr2DLL(arr);
    cout << isPalindrome(head);
    return 0;
}
