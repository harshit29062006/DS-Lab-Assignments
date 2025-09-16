/* 2. Write a program to count the number of occurrences of a given key in a singly linked
list and then delete all the occurrences.
Input: Linked List : 1->2->1->2->1->3->1 , key: 1
Output: Count: 4 , Updated Linked List: 2->2->3.  */

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
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int countAndDelete(Node* &head, int key) {
    int count = 0;

    // Delete from head if key is present
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 1, 3, 1};
    Node* head = convertArr2LL(arr);

    cout << "Linked List: ";
    print(head);

    int key = 1;
    int cnt = countAndDelete(head, key);

    cout << "Count: " << cnt << endl;
    cout << "Updated Linked List: ";
    print(head);

    return 0;
}
