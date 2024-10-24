// Menambahkan Elemen di Awal dan Akhir DLL
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

void insertFirst_2311104010(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
    {
        head->prev = newNode;
    }
    head = newNode;

    if (tail == nullptr)
    {
        tail = head;
    }
}

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
        cout << "1. Insert depan\n";
        cout << "2. Insert belakang\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Apa pilihanmu?: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukan data dari depan list data: ";
            cin >> data;
            insertFirst_2311104010(data);
            break;
        case 2:
            cout << "Masukan data dari depan list data: ";
            cin >> data;
            insertLast_2311104010(data);
            break;
        case 3:
            cout << "Ini keseluruhan data saat ini: ";
            displayForward_2311104010();
            break;
        case 4:
            cout << "Yok keluar\n";
            break;
        default:
            cout << "Tak ada opsinya.\n";
        }
    } while (choice != 4);

    return 0;
}
