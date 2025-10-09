/*2. Display all the node values in a circular linked list, repeating value of head node at the
end too.
Input: 20 → 100 → 40 → 80 → 60,
Output: 20 100 40 80 60 20.
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
    mover->next = head;
    return head;
}

void print(Node *head){
    if(head == NULL){
        cout << "List is Empty!";
        return;
    }
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << temp->data;
    cout << endl;
}

int main(){
    vector<int> arr = {20, 100, 80, 40, 60};
    Node* head = convertArr2LL(arr);
    print(head);
}
