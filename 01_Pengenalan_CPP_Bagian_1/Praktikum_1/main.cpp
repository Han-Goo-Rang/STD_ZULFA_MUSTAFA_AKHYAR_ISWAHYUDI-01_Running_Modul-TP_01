#include <iostream>
using namespace std;

int main(){
    int z;
    cout << "input mau angka berapapun : ";
    cin >> z;

    for (int i=z; i >= 1; i--) {
        for (int q=0; q<z-i; q++){
            cout << "  ";
        }

        for(int u=i; u >= 1; u--){
            cout <<u << " ";
        }
        cout << "* ";

        for (int u=1; u <= i; u++){
            cout << u << " ";
        }
        cout << endl;
    }
    for (int q=0; q<z; q++){
        cout << "  ";
    }

    cout << "*" << endl;
    return 0;
    }

