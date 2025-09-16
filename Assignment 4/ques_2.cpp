/*2) Develop a menu driven program demonstrating the following operations on Circular Queues:
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 10

struct CircularQueue{
    int arr[MAX];
    int front, rear;
};

CircularQueue init(){
    CircularQueue q;
    q.front = q.rear = -1;
    return q;
}

bool isEmpty(const CircularQueue &q){
    return (q.front == -1);
}

bool isFull(const CircularQueue &q){
    return ((q.rear + 1) % MAX == q.front);
}

void enqueue(CircularQueue &q, int x){
    if(isFull(q)){
        cout << "Overflow\n";
        return;
    }
    if(q.front == -1){ 
        q.front = q.rear = 0;
    } 
    else {
        q.rear = (q.rear + 1) % MAX;
    }
    q.arr[q.rear] = x;
    cout << x << " inserted into queue.\n";
}

void dequeue(CircularQueue &q){
    if(isEmpty(q)){
        cout << "Queue is EMPTY!\n";
        return;
    }
    cout << q.arr[q.front] << " removed from queue.\n";
    if(q.front == q.rear){ 
        q.front = q.rear = -1;
    } 
    else{
        q.front = (q.front + 1) % MAX;
    }
}

void peek(const CircularQueue &q) {
    if (isEmpty(q)) {
        cout << "Underflow\n";
        return;
    }
    cout << "Front element: " << q.arr[q.front] << endl;
}

void display(const CircularQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue is EMPTY!\n";
        return;
    }
    cout << "Queue elements: ";
    int i = q.front;
    while (true) {
        cout << q.arr[i] << " ";
        if (i == q.rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    CircularQueue q = init();
    int choice, val;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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
    } while (choice != 0);

    return 0;
}
