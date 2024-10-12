#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

float hitung_nilai_akhir(float uts, float uas, float tugas)
{
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

void input_mahasiswa(Mahasiswa &mhs)
{
    cout << "Masukkan nama mahasiswa: ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM mahasiswa: ";
    getline(cin, mhs.nim);
    cout << "Masukkan nilai UTS: ";
    cin >> mhs.uts;
    cout << "Masukkan nilai UAS: ";
    cin >> mhs.uas;
    cout << "Masukkan nilai Tugas: ";
    cin >> mhs.tugas;
    cin.ignore();
    mhs.nilai_akhir = hitung_nilai_akhir(mhs.uts, mhs.uas, mhs.tugas);
}

void tampil_mahasiswa(const Mahasiswa &mhs)
{
    cout << "Nama         : " << mhs.nama << endl;
    cout << "NIM          : " << mhs.nim << endl;
    cout << "Nilai UTS    : " << mhs.uts << endl;
    cout << "Nilai UAS    : " << mhs.uas << endl;
    cout << "Nilai Tugas  : " << mhs.tugas << endl;
    cout << "Nilai Akhir  : " << mhs.nilai_akhir << endl;
    cout << "-----------------------------" << endl;
}

int main()
{
    Mahasiswa mahasiswa[10];
    int jumlah_mahasiswa;

    while (true)
    {
        cout << "Masukkan jumlah mahasiswa (maks 10, bentukannya angka): ";
        cin >> jumlah_mahasiswa;

        if (cin.fail() || jumlah_mahasiswa < 1 || jumlah_mahasiswa > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bukan, maksude inputannya itu angka... dan gaboleh lebih dari 10" << endl;
            cout << endl;
        }
        else
        {
            cin.ignore();
            break;
        }
    }

    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        cout << "Data mahasiswa ke-" << i + 1 << ":" << endl;
        input_mahasiswa(mahasiswa[i]);
    }

    cout << "Data Mahasiswa yang Telah Dimasukkan:";
    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        tampil_mahasiswa(mahasiswa[i]);
    }

    return 0;
}
