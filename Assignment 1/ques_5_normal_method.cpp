/*5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming an array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix*/

#include<bits/stdc++.h>
using namespace std;

void diagnolMatrix(vector<vector<int>> &arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout << "arr[" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void triDiagnolMatrix(vector<vector<int>> &arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || i==j+1 || i==j-1){
                cout << "arr[" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void lowerTriangularMatrix(vector<vector<int>> &arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j){
                cout << "arr[" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void upperTriangularMatrix(vector<vector<int>> &arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j){
                cout << "arr[" << i << "][" << j << "]: ";
                cin >> arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void symmetricalMatrix(vector<vector<int>> &arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j){
                cout << "arr[" << i << "][" << j << "]: ";
                cin >> arr[i][j];
                arr[j][i] = arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr1(n, vector<int>(n,0));
    vector<vector<int>> arr2(n, vector<int>(n,0));
    vector<vector<int>> arr3(n, vector<int>(n,0));
    vector<vector<int>> arr4(n, vector<int>(n,0));
    vector<vector<int>> arr5(n, vector<int>(n,0));
    cout << "Diagnol Matrix:" << endl;
    diagnolMatrix(arr1, n);

    cout << "Tri-Diagnol Matrix" << endl;
    triDiagnolMatrix(arr2, n);

    cout << "Lower Triangular Matrix" << endl;
    lowerTriangularMatrix(arr3, n);
    
    cout << "Upper Triangular Matrix" << endl;
    upperTriangularMatrix(arr4, n);

    cout << "Symmetrical Matrix" << endl;
    symmetricalMatrix(arr5, n);

    return 0;
}
    