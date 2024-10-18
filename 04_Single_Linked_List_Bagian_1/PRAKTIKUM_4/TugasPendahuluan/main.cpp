#include <iostream>
#include "list.h"
using namespace std;
int main()
{
    List L;
    createList(L);
    infotype data;

    // 1
    cout << "Masukin nomor nim ke-1: ";
    cin >> data;
    insertFirst(L, allocate(data));
    cout << "List setelah masukin data ke-1: ";
    printInfo(L);

    // 2
    cout << "Masukkan nomor nim ke-2: ";
    cin >> data;
    insertFirst(L, allocate(data));

    cout << "List setelah masukin data ke-2: ";
    printInfo(L);

    // 3
    cout << "Masukkan nomor nim ke-3: ";
    cin >> data;
    insertFirst(L, allocate(data));

    // nampilinDiTerminal
    cout << "List setelah masukin data terakhir: ";
    printInfo(L);

    return 0;
}