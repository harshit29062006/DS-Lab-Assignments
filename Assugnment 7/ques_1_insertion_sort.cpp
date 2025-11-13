/*1. Write a program to implement following sorting techniques:
b. Insertion Sort*/

#include<bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> a){
    int n = a.size();
    for(int i=1;i<n;i++){
        int temp = a[i];
        int j = i;
        while(j>0 && a[j-1] > temp){
            a[j] = a[j-1];
            j = j-1;
        }
        a[j] = temp;
    }
    return a;
}

int main(){
    vector<int> arr = {1, 3, 5, 2, 4};
    vector<int> ans = insertionSort(arr);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
