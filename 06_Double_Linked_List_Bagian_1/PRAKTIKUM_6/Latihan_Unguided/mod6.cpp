#include <iostream>
#include <string>

using namespace std;

struct Buku
{
    int IDBuku;
    string Judul;
    string author;
    Buku *prev;
    Buku *next;
};

// Fungsi untuk menambahkan buku di akhir linked list
void addBooki_2311104010(Buku *&head, int id, string judul, string author)
{
    Buku *newBuku = new Buku;
    newBuku->IDBuku = id;
    newBuku->Judul = judul;
    newBuku->author = author;
    newBuku->next = nullptr;

    if (head == nullptr)
    {
        newBuku->prev = nullptr;
        head = newBuku;
    }
    else
    {
        Buku *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newBuku;
        newBuku->prev = temp;
    }
}

// Fungsi untuk menampilkan daftar buku dari awal ke akhir
void DisFirst_2311104010(Buku *head)
{
    Buku *temp = head;
    while (temp != nullptr)
    {
        cout << "ID Buku: " << temp->IDBuku << ", Judul: " << temp->Judul
             << ", author: " << temp->author << endl;
        temp = temp->next;
    }
}

// Fungsi untuk menampilkan daftar buku dari akhir ke awal
void DisLast_2311104010(Buku *head)
{
    if (head == nullptr)
        return;

    Buku *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    while (temp != nullptr)
    {
        cout << "ID Buku: " << temp->IDBuku << ", Judul: " << temp->Judul
             << ", author: " << temp->author << endl;
        temp = temp->prev;
    }
}

int main()
{
    Buku *head = nullptr;

    addBooki_2311104010(head, 101, "Unwritten Wanderer Saga I : Resilience Era's of Fathomless Warrior", "Bangjoule");
    addBooki_2311104010(head, 102, "Unwritten Wanderer Saga II : Eastern Daylight Has Sunken To The Naraka", "Bangjoule");
    addBooki_2311104010(head, 103, "Unwritten Wanderer Saga III : Across The Olde Covenant, In The Distance Luminaries Ocean", "Bangjoule");

    cout << "Daftar buku dari awal ke akhir: " << endl;
    DisFirst_2311104010(head);

    cout << "Daftar buku dari akhir ke awal: " << endl;
    DisLast_2311104010(head);

    return 0;
}
