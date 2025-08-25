/* 3) Design the Logic to Find a Missing Number in a Sorted Array.*/

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums){
    int n = nums.size();
    int sum1 = (n*(n+1))/2;
    int sum2 = 0;
    for(int i=0; i<n; i++) sum2 += nums[i];
    return sum1 - sum2;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    cout << missingNumber(nums);
    return 0;
}