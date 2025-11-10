#include <iostream>
using namespace std;

int main(){
    int r,c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    int a[10][10];
    cout << "Enter Matrix Elements: " << endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
        }
    }

    int compact[20][3], k = 0;
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

    cout << "Compact matrix: \n";
    cout << "Row Col Val\n";
    for(int i=0;i<k;i++){
        cout << compact[i][0] << " " << compact[i][1] << " " << compact[i][2] << endl;
    }

    int simple[20][3], t = 0;
    for(int col=0;col < c; col ++){
        for(int i=0;i<k;i++){
            if(compact[i][1] == col){
                simple[t][0] = compact[i][1];
                simple[t][1] = compact[i][0];
                simple[t][2] = compact[i][2];
                t++;
            }
        }
    }

    cout << "Simple Transpose: \n";
    cout << "Row Col Val\n";
    for(int i=0;i<t;i++){
        cout << simple[i][0] << " " << simple[i][1] << " " << simple[i][2] << endl;
    }
}





