/*Sort an array of 0s, 1s and 2s - Dutch National Flag Problem
Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e.,
put all 0s first, then all 1s and all 2s in last.
*/

#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr){
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;

    while (mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr = {0, 1, 0, 1, 1, 2, 1, 0};
    sort012(arr);
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
