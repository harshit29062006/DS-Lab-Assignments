/* 4) Implement the logic to
a. Reverse the elements of an array
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, i;
  cin >> n;
  int arr[n];
  for(i=0;i<n;i++){
    cin >> arr[i];
  }
  
  for(i=0;i<n/2;i++){
    int temp = arr[n-i-1];
    arr[n-i-1] = arr[i];
    arr[i] = temp;
  }
  
  for(i=0;i<n;i++){
    cout << arr[i];
  }
}