/*Given a fixed-length integer array arr, duplicate each occurrence of two (2), shifting the
remaining elements to the right.
Note that elements beyond the length of the original array are not*/

#include <bits/stdc++.h>
using namespace std;

void duplicateTwos(vector<int>& arr){
    int n = arr.size();
    int twos = 0;

    for(int x : arr){
        if(x == 2) twos++;
    }

    int i = n - 1;
    int j = n + twos - 1;

    while(i >= 0 && j >= 0){
        if(j < n) 
            arr[j] = arr[i];  
        if(arr[i] == 2){
            j--;
            if(j < n) 
                arr[j] = 2;   
        }
        i--;
        j--;
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 2, 4, 5};
    duplicateTwos(arr);

    for(int i=0; i<6; i++) 
        cout << i << " ";
    return 0;
}
