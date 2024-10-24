// Menampilkan Elemen dari Depan ke Belakang dan Sebaliknya
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

// Tampil dari depan dulu
void displayAscending_2311104010()
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

// Tampil dari belakang dulu
void displayDescending_2311104010()
{
    Node *temp = tail;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->prev != nullptr)
            cout << " <-> ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    int choice, data;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Masukan data diakhir List\n";
        cout << "2. Tampilkan seluruh data urut dari belakang\n";
        cout << "3. Tampilkan seluruh data urut dari depan\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukan data diakhir List: ";
            cin >> data;
            insertLast_2311104010(data);
            break;
        case 2:
            cout << "Tampilkan seluruh data urut dari belakang: ";
            displayAscending_2311104010();
            break;
        case 3:
            cout << "Tampilkan seluruh data urut dari depan: ";
            displayDescending_2311104010();
            break;
        case 4:
            cout << "Exiting\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
