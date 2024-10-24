// Mencari Elemen Tertentu dalam Single Linked List (SLL)
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head;
};

void insertLast_2311104010(List &L, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (L.head == NULL)
    {
        L.head = newNode;
    }
    else
    {
        Node *temp = L.head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchElement_2311104010(List L, int i)
{
    Node *current = L.head;
    int position = 1;

    while (current != NULL)
    {
        if (current->data == i)
        {
            cout << "Elemen ditemukan di alamat: " << current << " pada urutan ke-" << position << endl;
            return;
        }
        current = current->next;
        position++;
    }

    cout << "Elemen tidak ditemukan dalam list." << endl;
}

int main()
{
    List L;
    L.head = NULL;
    int value;

    // Memasukkan 6 elemen ke dalam list
    for (int i = 0; i < 6; i++)
    {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> value;
        insertLast_2311104010(L, value);
    }

    // Mencari elemen tertentu
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> value;
    searchElement_2311104010(L, value);

    return 0;
}
