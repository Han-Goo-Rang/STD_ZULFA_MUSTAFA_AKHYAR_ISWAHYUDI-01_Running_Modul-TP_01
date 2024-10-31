#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull()
{
    return top == maksimal;
}

bool isEmpty()
{
    return top == 0;
}

void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Stack-nya penuh woy" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "gada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = ""; // Menghapus elemen teratas
        top--;
    }
}

void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "gada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top - posisi;
        if (index >= 0 && index < top)
        {
            cout << "Posisi ke- " << posisi << " adalah " << arrayBuku[index] << endl;
        }
        else
        {
            cout << "Posisi diluar jangkauan" << endl;
        }
    }
}

int countStack()
{
    return top;
}

void changeArrayBuku(int posisi, string data)
{
    int index = top - posisi;
    if (index >= 0 && index < top)
    {
        arrayBuku[index] = data;
    }
    else
    {
        cout << "Kelebihan posisinya" << endl;
    }
}

void destroyArrayBuku()
{
    for (int i = top - 1; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Gada data yang bisa dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Bahasa Indonesia");
    pushArrayBuku("Ipa");
    pushArrayBuku("IPS");
    pushArrayBuku("Kimia");

    cetakArrayBuku();
    cout << "\n"
         << endl;

    cout << "Stack-nya penuh? " << (isFull() ? "Ya" : "Tidak") << endl;
    cout << "Stack-nya kosong? " << (isEmpty() ? "Ya" : "Tidak") << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Keseluruhan data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n"
         << endl;

    destroyArrayBuku();
    cout << "Top setelah destroy : " << top << endl;
    cetakArrayBuku();

    return 0;
}
