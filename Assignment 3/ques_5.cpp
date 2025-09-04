// 5. Write a program for the evaluation of a Postfix expression.

#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;
void push(int val) {
    if (top < MAX - 1) {
        stackArr[++top] = val;
    }
}

int pop() {
    if (top == -1) return 0;
    return stackArr[top--];
}

int evaluatePostfix(const char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isdigit(c)) {
            push(c - '0'); 
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop(); 
}

int main(){
    char exp[MAX];
    cout << "Enter Postfix expression: ";
    cin.getline(exp, MAX);

    int result = evaluatePostfix(exp);
    cout << "Result = " << result << endl;

    return 0;
}