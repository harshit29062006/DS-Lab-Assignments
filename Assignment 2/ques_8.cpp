/*8) Write a program to count the total number of distinct elements in an array of
length n.*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }
    cout << "Total number of distinct elements: " << count << endl;
    return 0;
}