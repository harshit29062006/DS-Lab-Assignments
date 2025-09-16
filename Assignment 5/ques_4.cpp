/*4. Write a program to reverse a linked list.
Input: 1->2->3->4->NULL
Output: 4->3->2->1->NULL
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node *next1) {
        data = data1;
        next = next1;
    }
};

Node* convertArr2LL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << "->NULL" << endl;
}

Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;  
        prev = curr;         
        curr = next;         
    }
    return prev;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    Node* head = convertArr2LL(arr);

    cout << "Original Linked List: ";
    print(head);

    head = reverseLL(head);

    cout << "Reversed Linked List: ";
    print(head);

    return 0;
}
