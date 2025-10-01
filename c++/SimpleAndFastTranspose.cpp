#include <iostream>
using namespace std;

#define MAX 100

// Function to display a matrix
void displayMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to display 3-tuple sparse representation
void displaySparse(int mat[][3], int n) {
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < n; i++) {
        cout << mat[i][0] << "\t" << mat[i][1] << "\t" << mat[i][2] << endl;
    }
    cout << endl;
}

// Convert normal matrix to sparse (3-tuple compact form)
int convertToSparse(int mat[MAX][MAX], int rows, int cols, int sparse[][3]) {
    int k = 1; // index for non-zero entries
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1; // number of non-zero values
    return k; // total rows in sparse matrix
}

// Simple transpose of sparse matrix
void simpleTranspose(int a[][3], int b[][3]) {
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];

    int k = 1;
    for (int col = 0; col < a[0][1]; col++) {
        for (int i = 1; i <= a[0][2]; i++) {
            if (a[i][1] == col) {
                b[k][0] = a[i][1];
                b[k][1] = a[i][0];
                b[k][2] = a[i][2];
                k++;
            }
        }
    }
}

// Fast transpose of sparse matrix
void fastTranspose(int a[][3], int b[][3]) {
    int rowSize = a[0][0], colSize = a[0][1], terms = a[0][2];
    int rowTerms[MAX], startPos[MAX];

    b[0][0] = colSize;
    b[0][1] = rowSize;
    b[0][2] = terms;

    if (terms > 0) {
        for (int i = 0; i < colSize; i++)
            rowTerms[i] = 0;

        for (int i = 1; i <= terms; i++)
            rowTerms[a[i][1]]++;

        startPos[0] = 1;
        for (int i = 1; i < colSize; i++)
            startPos[i] = startPos[i - 1] + rowTerms[i - 1];

        for (int i = 1; i <= terms; i++) {
            int j = startPos[a[i][1]];
            b[j][0] = a[i][1];
            b[j][1] = a[i][0];
            b[j][2] = a[i][2];
            startPos[a[i][1]]++;
        }
    }
}

int main() {
    int rows, cols;
    int mat[MAX][MAX];
    int sparse[MAX][3], simple[MAX][3], fast[MAX][3];

    cout << "Enter number of rows and columns of matrix: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(mat, rows, cols);

    // Convert to sparse
    int sparseSize = convertToSparse(mat, rows, cols, sparse);
    cout << "\nCompact Sparse Matrix (3-tuple form):\n";
    displaySparse(sparse, sparseSize);

    // Simple Transpose
    simpleTranspose(sparse, simple);
    cout << "Simple Transpose of Sparse Matrix:\n";
    displaySparse(simple, sparseSize);

    // Fast Transpose
    fastTranspose(sparse, fast);
    cout << "Fast Transpose of Sparse Matrix:\n";
    displaySparse(fast, sparseSize);

    return 0;
}
