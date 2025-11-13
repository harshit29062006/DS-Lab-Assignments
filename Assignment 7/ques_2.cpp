/*2. A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
every pass on the array, and place it at its correct position. The idea is to take also the maximum on
every pass and place it at its correct position. So in every pass, we keep track of both maximum and
minimum and array becomes sorted from both ends. Implement this logic.*/
  
#include<bits/stdc++.h>
using namespace std;

void improvedSelectionSort(vector<int> &arr) {
    int n = arr.size();
    int start = 0, end = n - 1;

    while(start < end){
        int minIndex = start;
        int maxIndex = start;

        for(int i=start;i<=end;i++){
            if(arr[i] < arr[minIndex])
                minIndex = i;
            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[start], arr[minIndex]);

        if(maxIndex == start)
            maxIndex = minIndex;

        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

int main() {
    vector<int> arr = {5, 6, 2, 3, 1, 9};
    improvedSelectionSort(arr);

    for(int i=0;i<arr.size();i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
