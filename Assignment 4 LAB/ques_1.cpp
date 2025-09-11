#include <bits/stdc++.h>
using namespace std;

#define MAX 100

struct Queue{
    int arr[MAX];
    int front, rear;
};

Queue init(){
    Queue q;
    q.front = q.rear = -1;
    return q;
}

bool isEmpty(Queue q){
    return (q.front == -1);
}

bool isFull(Queue q){
    return (q.rear == MAX - 1);
}

void enqueue(Queue &q, int x){
    if(isFull(q)){
        cout << "Overflow\n";
        return;
    }
    if(q.front == -1) q.front = 0;
    q.arr[++q.rear] = x;
    cout << x << " inserted into queue.\n";
}

void dequeue(Queue &q){
    if(isEmpty(q)){
        cout << "Underflow\n";
        return;
    }
    cout << q.arr[q.front] << " removed from queue.\n";
    if (q.front == q.rear){
        q.front = q.rear = -1;
    }
    else{
        q.front++;
    }
}

void peek(Queue q){
    if(isEmpty(q)){
        cout << "Queue is EMPTY!\n";
        return;
    }
    cout << "Front element: " << q.arr[q.front] << endl;
}

void display(Queue q){
    if(isEmpty(q)){
        cout << "Underflow\n";
        return;
    }
    cout << "Queue elements: ";
    for(int i = q.front; i <= q.rear; i++){
        cout << q.arr[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q = init();
    int x, val;

    do{
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> x;

        switch (x){
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                enqueue(q, val);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                display(q);
                break;
            case 5:
                cout << (isEmpty(q) ? "Queue is EMPTY\n" : "Queue is NOT empty\n");
                break;
            case 6:
                cout << (isFull(q) ? "Queue is FULL\n" : "Queue is NOT full\n");
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }while (x != 0);
    return 0;
}
