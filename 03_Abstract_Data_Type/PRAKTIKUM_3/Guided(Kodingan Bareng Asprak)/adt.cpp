#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float ratarata(mahasiswa m);

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << ratarata(mhs);
    return 0;
}

void inputMhs(mahasiswa &m)
{
    cout << "input nim = ";
    cin >> m.nim;
    cout << "input nilai1 = ";
    cin >> m.nilai1;
    cout << "input nilai1 = ";
    cin >> m.nilai2;
}

float ratarata(mahasiswa m)
{
    return (m.nilai1 + m.nilai2) / 2.0;
}