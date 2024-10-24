#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa
{
    int NIM;
    string Nama;
    Mahasiswa *next;
};

// Fungsi untuk menambahkan data mahasiswa ke linked list
void addMhs_2311104010(Mahasiswa *&head, int nim, string nama)
{
    Mahasiswa *newMahasiswa = new Mahasiswa;
    newMahasiswa->NIM = nim;
    newMahasiswa->Nama = nama;
    newMahasiswa->next = nullptr;

    if (head == nullptr)
    {
        head = newMahasiswa;
    }
    else
    {
        Mahasiswa *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newMahasiswa;
    }
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
void findMhs_2311104010(Mahasiswa *head, int nim)
{
    Mahasiswa *temp = head;
    while (temp != nullptr)
    {
        if (temp->NIM == nim)
        {
            cout << "Data mahasiswa ditemukan: " << temp->Nama << " (NIM: " << temp->NIM << ")" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
}

// Fungsi untuk menampilkan seluruh mahasiswa
void displayMhs_2311104010(Mahasiswa *head)
{
    Mahasiswa *temp = head;
    while (temp != nullptr)
    {
        cout << "NIM: " << temp->NIM << ", Nama: " << temp->Nama << endl;
        temp = temp->next;
    }
}

// Fungsi menu
void menu()
{
    cout << "===== Menu Mahasiswa =====" << endl;
    cout << "1. Add (nambah data)" << endl;
    cout << "2. search (cari nim-nya ya)" << endl;
    cout << "3. display (tampilin semua data-nya)" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih opsi: ";
}

int main()
{
    Mahasiswa *head = nullptr;
    int pilihan;
    int nim;
    string nama;

    do
    {
        menu();
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nama: ";
            cin.ignore(); // Membersihkan buffer newline
            getline(cin, nama);
            addMhs_2311104010(head, nim, nama);
            cout << "Data mahasiswa berhasil ditambahkan." << endl;
            break;

        case 2:
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> nim;
            findMhs_2311104010(head, nim);
            break;

        case 3:
            cout << "Daftar seluruh mahasiswa:" << endl;
            displayMhs_2311104010(head);
            break;

        case 4:
            cout << "Keluar dari program." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << endl;
    } while (pilihan != 4);

    return 0;
}
