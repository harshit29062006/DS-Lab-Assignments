/*1. Write a program to implement following sorting techniques:
a. Selection Sort
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> a){
    int n = a.size();
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    return a;
}

int main(){
    vector<int> arr = {1, 3, 5, 2, 4};
    vector<int> ans = selectionSort(arr);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
