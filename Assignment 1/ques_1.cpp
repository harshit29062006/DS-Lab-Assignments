/* 1) Develop a Menu driven program to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  
  cout << "Enter 1 to create an array." << endl;
  cout << "Enter 2 to display an array." << endl;
  cout << "Enter 3 to insert an element in the array." << endl;
  cout << "Enter 4 to delete an element in the array." << endl;
  cout << "Enter 5 for linear search for an element." << endl;
  cout << "Enter 6 to exit the MENU." << endl;
  cout << "Enter: ";
  int input;
  do{
    cin >> input;
    switch(input){
    case 1:{
      int n;
      cin >> n;
      int arr[n];
      int i, j;
      for(i=0;i<n;i++){
        cin >> arr[i];
      }
      break;
    }
    case 2:{
      int n;
      cin >> n;
      int arr[n];
      int j;
      for(j=0;j<n;j++){
        cout << arr[j];
      }
      break;
    }
    case 3:{
      int n, ind, item, i;
      cin >> n;
      cout << "Enter the index:";
      cin >> ind;
     cout << "Enter the element:"; 
      cin >> item;
      int arr[n];
      for(i=0;i<n;i++){
       cin >> arr[i];
      }
      n=n+1;
      for(i=n;i>ind-1;i--){
       arr[i] = arr[i-1];
      }
      arr[ind] = item;
      for(i=0;i<n;i++){
       cout << arr[i];
      }
      break;
    }
    case 4:{
      int n, ind, item, i;
      cin >> n;
      cout << "Enter the index:";
      cin >> ind;
      int arr[n];
      for(i=0;i<n;i++){
       cin >> arr[i];
      }
      for(i=ind+1;i<n;i++){
        arr[i-1] = arr[i];
      }
      n=n-1;
      for(i=0;i<n;i++){
       cout << arr[i];
      }
      break;
    }
    case 5: {
      int n, i, item;
      cin >> n;
      cout << "Enter the element: ";
      cin >> item;
      int arr[n];
      for(i=0;i<n;i++){
        cin >> arr[i];
      }
      for(i=0;i<n;i++){
        if(arr[i] == item){
         cout << "Element found at index: " << i;
         break;
        }
      }
      break;
    }
    case 6:
      cout << "MENU is Exited!!";
  }
  }while(input < 6);
  return 0;
}
