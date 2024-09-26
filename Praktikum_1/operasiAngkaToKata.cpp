#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"satu", "dua", "tiga", "empat", "lima"};
string belasan[] = {"belas"};
string puluhan[] = {"puluh"};

string konversi(int nomor) {
    if (nomor == 0)
        return "Nol";
    else if (nomor < 10)
        return satuan[nomor];
    else if (nomor < 20)
        return satuan, belasan[nomor];
    else if (nomor < 100) {
        int puluh = nomor / 10;
        int sisa = nomor % 10;
        if (sisa == 0)
            return puluhan[satuan, puluh];
        else
            return puluhan[satuan, puluh] + "" + satuan[sisa];
        } else if (nomor == 100) {
            return "seratus";
        }
        return "";
}

int main() {
    int nomor;
    cout << "Input angka antara 0-100 : ";
    cin >> angka;

    if (nomor < 0 || nomor > 100) {
        cout << "Eiyo, tidak bisa. Bukan begitu inputan angkanya." << endl;
    } else {
        cout << nomor << " : " << konversi(nomor) << endl;
    }
    return 0;
}
