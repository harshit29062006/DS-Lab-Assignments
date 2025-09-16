
/*1. Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().*/

#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    static const int n = 100;
    int arr[n];
    int top;

    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == n - 1)
            cout << "Stack Overflow\n";
        else {
            arr[++top] = x;
        }
    }

    void pop() {
        if (top == -1)
            cout << "Stack Underflow\n";
        else {
            cout << "Popped Element: " << arr[top--] << endl;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == n - 1;
    }

    void display() {
        if (top == -1)
            cout << "Stack is Empty\n";
        else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void peek() {
        if (top == -1)
            cout << "Stack is empty\n";
        else {
            cout << "Top Element: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s;
    int x, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n";
        cin >> x;

        switch (x) {
        case 1:
            cout << "Enter the value to be pushed: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isEmpty())
                cout << "Stack is Empty\n";
            else
                cout << "Stack is NOT Empty\n";
            break;
        case 4:
            if (s.isFull())
                cout << "Stack is Full\n";
            else
                cout << "Stack is NOT Full\n";
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.peek();
            break;
        default:
            cout << "Invalid choice! Please enter between 1 and 7.\n";
            break;
        }
    } while (x != 7);

    return 0;
}
