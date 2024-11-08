#include <iostream>
using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull()
{

    if (back == maksimalQueue)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueueAntrian(string data)
{
    if (isFull())
    {
        cout << "Antrian sudah penuh" << endl;
    }
    else
    {
        if (isEmpty())
        {
            queueTeller[0] = data;
            back++;
            front++;
        }
        else
        {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() // kurangi antrian data
{
    if (isEmpty())
    {
        cout << "Antrian sudah kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back - 1; i++) // pindahkan data kedepan
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = ""; // kosongkan posisi terakhir

        back--;
    }
}





int countQueue()
{
    // Hitung total antrian data
    return back;
}

void clearQueue()
{
    // Menghapus Antrian
    if (isEmpty())
    {
        cout << "Antrian sudah kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue()
{
    // Lihat Antrian
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}




int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");

    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();

    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();

    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}