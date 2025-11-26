// 5. Implement Heapsort (Increasing/Decreasing order).

#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i, bool increasing){
    int extreme = i;      
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(increasing){
        if(left < n && arr[left] > arr[extreme]) extreme = left;
        if(right < n && arr[right] > arr[extreme]) extreme = right;
    } 
    else{
        if(left < n && arr[left] < arr[extreme]) extreme = left;
        if(right < n && arr[right] < arr[extreme]) extreme = right;
    }

    if(extreme != i){
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}

void heapSort(int arr[], int n, bool increasing = true){

    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main(){
    int arr[] = {10, 3, 5, 30, 2};
    int n = 5;

    heapSort(arr, n, true);   

    cout << "Sorted: ";
    for(int x : arr) cout << x << " ";
}
