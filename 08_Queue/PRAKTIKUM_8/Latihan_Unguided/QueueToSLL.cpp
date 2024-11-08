#include <iostream>
using namespace std;

struct Node
{
    string namaMahasiswa;
    string nimMahasiswa;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;


bool isEmpty()
{
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim)
{
    Node *newNode = new Node();
    newNode->namaMahasiswa = nama;
    newNode->nimMahasiswa = nim;
    newNode->next = nullptr;

    // Jika antrian kosong atau NIM baru lebih kecil dari NIM di front
    if (isEmpty() || nim < front->nimMahasiswa)
    {
        newNode->next = front; // Letakkan di depan
        front = newNode;
        if (back == nullptr)
        {
            back = newNode; // Jika antrian sebelumnya kosong, back juga menunjuk ke newNode
        }
    }
    else
    {
        // Cari posisi yang tepat untuk menyisipkan newNode
        Node *current = front;
        while (current->next != nullptr && current->next->nimMahasiswa < nim)
        {
            current = current->next;
        }
        newNode->next = current->next; // Sisipkan newNode
        current->next = newNode;

        if (newNode->next == nullptr)
        {
            back = newNode; // Update back jika newNode adalah elemen terakhir
        }
    }
    cout << nama << " dengan NIM " << nim << " dimasukkan ke antrian." << endl;
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian sudah kosong" << endl;
    }
    else
    {
        Node *temp = front;
        cout << "Menghapus: " << front->namaMahasiswa << " dengan NIM " << front->nimMahasiswa << endl;
        front = front->next;

        if (front == nullptr)
        {
            back = nullptr; // Jika antrian kosong, set back ke nullptr
        }

        delete temp;
    }
}

int countQueue()
{
    int count = 0;
    Node *temp = front;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeueAntrian();
    }
    cout << "Antrian dikosongkan." << endl;
}

void viewQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong." << endl;
    }
    else
    {
        Node *temp = front;
        int pos = 1;
        cout << "Data antrian mahasiswa:" << endl;
        while (temp != nullptr)
        {
            cout << pos << ". Nama: " << temp->namaMahasiswa << ", NIM: " << temp->nimMahasiswa << endl;
            temp = temp->next;
            pos++;
        }
    }
}

int main()
{
    int pilihan;
    string nama, nim;

    do
    {
        cout << "\nMenu Antrian Mahasiswa:\n";
        cout << "1. Tambah Mahasiswa ke Antrian\n";
        cout << "2. Hapus Mahasiswa dari Antrian\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Hitung Jumlah Antrian\n";
        cout << "5. Kosongkan Antrian\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama mahasiswa: ";
            cin.ignore(); // untuk membersihkan buffer input
            getline(cin, nama);
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim;
            enqueueAntrian(nama, nim);
            break;

        case 2:
            dequeueAntrian();
            break;

        case 3:
            viewQueue();
            break;

        case 4:
            cout << "Jumlah antrian = " << countQueue() << endl;
            break;

        case 5:
            clearQueue();
            break;

        case 6:
            cout << "Keluar dari program." << endl;
            break;

        default:
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 6);

    return 0;
}
