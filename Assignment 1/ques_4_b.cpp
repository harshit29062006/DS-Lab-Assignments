/*4) Implement the logic to
b. Find the matrix multiplication
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n1, m1, n2, m2, i, j, k;
  cout << "Enter the number of rows and columns for 1st matrix: ";
  cin >> n1 >> m1;
  int arr1[n1][m1];
  
  cout << "Enter the number of rows and columns for 2nd matrix: ";
  cin >> n2 >> m2;
  int arr2[n2][m2];
  
  for(i=0;i<n1;i++){
    for(j=0;j<m1;j++){
      cin >> arr1[i][j];
    }
  }
  
  for(i=0;i<n2;i++){
    for(j=0;j<m2;j++){
      cin >> arr2[i][j];
    }
  }
  
  int arr3[n1][m2] = {0};
  
  if(m1==n2){
    for(i=0;i<n1;i++){
      for(j=0;j<m2;j++){
        for(k=0;k<m1;k++){
          arr3[i][j] += arr1[i][k] * arr2[k][j]; 
        }
      }
    }
  }
  else{
    cout << "Matrix Multiplication is not possible";
  }
  
  for(i=0;i<n1;i++){
    for(j=0;j<m2;j++){
      cout << arr3[i][j] << " ";
    }
    cout << endl;
  }
}