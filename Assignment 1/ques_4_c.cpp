/*4) Implement the logic to
c. Find the Transpose of a Matrix
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m, i, j;
  cout << "Enter the number of rows and columns: ";
  cin >> n >> m;
  int arr[n][m];
  
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cin >> arr[i][j];
    }
  }
  
  
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
       int temp = arr[i][j];
       arr[i][j] = arr[j][i];
       arr[j][i] = temp;
    }
  }
  
  
  for(i=0;i<n;i++){
    for(j=0;j<m;j++){
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}