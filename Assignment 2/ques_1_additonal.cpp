/*Find two numbers in an array whose difference equals K. Given an array arr[] and a
positive integer k, the task is to count all pairs (i, j) such that i < j and absolute value of
(arr[i] - arr[j]) is equal to k.
*/

#include <bits/stdc++.h>
using namespace std;

int countPairsWithDiffK(vector<int> &arr, int k){
    unordered_map<int, int> freq;
    int cnt = 0;

    for(int num : arr) {
        if(freq.find(num - k) != freq.end()){
            cnt += freq[num - k];
        }
        if(freq.find(num + k) != freq.end()){
            cnt += freq[num + k];
        }
        freq[num]++;
    }
    return cnt;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << countPairsWithDiffK(arr, k);
    return 0;
}
