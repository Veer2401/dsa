#include <iostream>
using namespace std;

int main(){
    int r,c;
    cout << "Enter rows: ";
    cin >> r;
    cout << "Enter columns: ";
    cin >> c;

    int a[10][10];
    cout << "Enter matrix elements:\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
        }
    }

    int compact[20][3], k=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j] != 0){
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = a[i][j];
                k++;
            }
        }
    }

    compact[0][0] = r;
    compact[0][1] = c;
    compact[0][2] = k-1;

    cout << "Compact matrix:\n ";
    cout << "ROW COL VAL\n";
    for(int i=0;i<k;i++){
        cout << compact[i][0] << " " << compact[i][1] << " " << compact[i][2] << endl;
    }

    int transpose[20][3],t=1;
    for(int col=0;col<c;col++){
        for(int i=1;i<k;i++){
            if(compact[i][1] == col){
                transpose[t][0] = compact[i][1];
                transpose[t][1] = compact[i][0];
                transpose[t][2] = compact[i][2];
                t++;
            }
        }
    }

    transpose[0][0] = compact[0][1];
    transpose[0][1] = compact[0][0];
    transpose[0][2] = compact[0][2];

    cout << "Transpose matrix:\n";
    cout << "ROW COL VAL\n";
    for(int i=0;i<t;i++){
        cout << transpose[i][0] << " " << transpose[i][1] << " " << transpose[i][2] << endl;
    }

    return 0;
}
