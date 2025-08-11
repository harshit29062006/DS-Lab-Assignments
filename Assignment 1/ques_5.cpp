/* 5) Write a program to find sum of every row and every column in a two-dimensional
array. */

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
    int row_sum = 0;
    for(j=0;j<m;j++){
      row_sum += arr[i][j];
    }
    cout << "Sum of row" << i << " " << row_sum;
    cout << endl;
  }
  
  for(i=0;i<n;i++){
    int column_sum = 0;
    for(j=0;j<m;j++){
      column_sum += arr[i][j];
    }
    cout << "Sum of column" << i << " " << column_sum;
    cout << endl;
  }
  
}