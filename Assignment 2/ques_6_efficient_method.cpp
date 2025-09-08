/* 6) Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
(b) Addition of two matrices.
(c) Multiplication of two matrices.
*/

#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

void printSparse(Triplet a[], int size) {
    cout << "Row Col Val\n";
    for (int i = 0; i < size; i++) {
        cout << a[i].row << "   " << a[i].col << "   " << a[i].val << endl;
    }
}

int convertToSparse(int mat[10][10], int r, int c, Triplet sparse[]) {
    int k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = mat[i][j];
                k++;
            }
        }
    }
    return k;
}

int transpose(Triplet a[], int n, Triplet b[]) {
    for (int i = 0; i < n; i++) {
        b[i].row = a[i].col;
        b[i].col = a[i].row;
        b[i].val = a[i].val;
    }
    return n;
}

int add(Triplet a[], int n1, Triplet b[], int n2, Triplet c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            c[k] = a[i];
            c[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        } else if ((a[i].row < b[j].row) || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < n1) c[k++] = a[i++];
    while (j < n2) c[k++] = b[j++];
    return k;
}

int multiply(Triplet a[], int n1, Triplet b[], int n2, Triplet c[]) {
    int k = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (a[i].col == b[j].row) {
                int found = -1;
                for (int x = 0; x < k; x++) {
                    if (c[x].row == a[i].row && c[x].col == b[j].col) {
                        found = x;
                        break;
                    }
                }
                if (found != -1) {
                    c[found].val += a[i].val * b[j].val;
                } else {
                    c[k].row = a[i].row;
                    c[k].col = b[j].col;
                    c[k].val = a[i].val * b[j].val;
                    k++;
                }
            }
        }
    }
    return k;
}

int main() {
    int r, c;
    cout << "Enter rows and cols of matrices: ";
    cin >> r >> c;

    int mat1[10][10], mat2[10][10];
    cout << "Enter elements of Matrix 1:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat1[i][j];

    cout << "Enter elements of Matrix 2:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat2[i][j];

    Triplet A[100], B[100], C[100];
    int n1 = convertToSparse(mat1, r, c, A);
    int n2 = convertToSparse(mat2, r, c, B);

    cout << "\nSparse Matrix 1:\n";
    printSparse(A, n1);

    cout << "\nSparse Matrix 2:\n";
    printSparse(B, n2);

    Triplet T[100];
    int nt = transpose(A, n1, T);
    cout << "\nTranspose of Matrix 1:\n";
    printSparse(T, nt);

    int na = add(A, n1, B, n2, C);
    cout << "\nAddition (Matrix1 + Matrix2):\n";
    printSparse(C, na);

    Triplet M[100];
    int nm = multiply(A, n1, B, n2, M);
    cout << "\nMultiplication (Matrix1 * Matrix2):\n";
    printSparse(M, nm);

    return 0;
}
