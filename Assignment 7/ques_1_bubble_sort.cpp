/*1. Write a program to implement following sorting techniques:
c. Bubble Sort
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> a){
    int n = a.size();
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return a;
}

int main(){
    vector<int> arr = {1, 3, 5, 2, 4};
    vector<int> ans = bubbleSort(arr);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
