/*2. Given a string, reverse it using STACK. For example “DataStructure” should be output as
“erutcurtSataD.”*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "DataStructure";
    int len = str.length();
    char stack[100];
    int top = -1;
    for(int i=0;i<len;i++){
        stack[++top] = str[i];
    }
    cout << "Reversed String: ";
    while(top != -1){
        cout << stack[top--];
    }
    return 0;
}
