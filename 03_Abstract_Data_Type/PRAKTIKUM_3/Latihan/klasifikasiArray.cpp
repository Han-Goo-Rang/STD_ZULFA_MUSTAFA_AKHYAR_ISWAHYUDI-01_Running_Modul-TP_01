#include <iostream>
using namespace std;

void tampilkanArray(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tukarSeluruhElemenArray(int arr1[3][3], int arr2[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int temp = arr1[i][j];
            arr1[i][j] = arr2[i][j];
            arr2[i][j] = temp;
        }
    }
}

void tukarPointer(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    // Deklarasi dua array 2D ukuran 3x3
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int array2[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};

    int a = 10, b = 20;
    int *ptr1 = &a;
    int *ptr2 = &b;

    cout << "Array 1 sebelum penukaran:" << endl;
    tampilkanArray(array1);

    cout << "Array 2 sebelum penukaran:" << endl;
    tampilkanArray(array2);

    tukarSeluruhElemenArray(array1, array2);

    cout << "Array 1 setelah penukaran:" << endl;
    tampilkanArray(array1);

    cout << "Array 2 setelah penukaran:" << endl;
    tampilkanArray(array2);

    cout << "Nilai ptr1 sebelum: " << *ptr1 << endl;
    cout << "Nilai ptr2 sebelum: " << *ptr2 << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Nilai ptr1 setelah: " << *ptr1 << endl;
    cout << "Nilai ptr2 setelah: " << *ptr2 << endl;

    return 0;
}
