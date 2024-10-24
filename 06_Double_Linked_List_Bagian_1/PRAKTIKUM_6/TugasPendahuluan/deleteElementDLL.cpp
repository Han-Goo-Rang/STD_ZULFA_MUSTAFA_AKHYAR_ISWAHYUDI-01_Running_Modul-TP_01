// Menghapus Elemen di Awal dan Akhir DLL
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void insertLast_2311104010(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr)
    {
        tail->next = newNode;
    }
    tail = newNode;

    if (head == nullptr)
    {
        head = tail;
    }
}

void deleteFirst_2311104010()
{
    if (head == nullptr)
        return;

    Node *temp = head;
    head = head->next;

    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }

    delete temp;
}

void deleteLast_2311104010()
{
    if (tail == nullptr)
        return;

    Node *temp = tail;
    tail = tail->prev;

    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }

    delete temp;
}

void displayForward_2311104010()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice, data;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Masukan data diakhir DLL\n";
        cout << "2. Hapus data pertama\n";
        cout << "3. Hapus data terakhir\n";
        cout << "4. Tampilkan keseluruhan\n";
        cout << "5. Keluar\n";
        cout << "Masukan opsinya: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukan data diakhir DLL: ";
            cin >> data;
            insertLast_2311104010(data);
            break;
        case 2:
            deleteFirst_2311104010();
            cout << "Hapus data pertama.\n";
            break;
        case 3:
            deleteLast_2311104010();
            cout << "Hapus data terakhir.\n";
            break;
        case 4:
            cout << "Ini keseluruhan datanya saat ini: ";
            displayForward_2311104010();
            break;
        case 5:
            cout << "Lagi keluar\n";
            break;
        default:
            cout << "Gada opsinya.\n";
        }
    } while (choice != 5);

    return 0;
}
