/* 2) Design the logic to remove the duplicate elements from an Array and after the
deletion the array should contain the unique elements.
*/
#include<bits/stdc++.h>
using namespace std;

int main (){
  int n, i, j, k;
  cin >> n;
  int arr[n];
  for(i=0;i<n;i++){
    cin >> arr[i];
  }
  
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(arr[i] == arr[j]){
        arr[j] = arr[j+1];
        n--;
      }
    }
  }
  for(i=0;i<n;i++){
    cout << arr[i];
  }
  return 0;
}
