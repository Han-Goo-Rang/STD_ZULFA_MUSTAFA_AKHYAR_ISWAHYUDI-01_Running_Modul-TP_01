// /Menambahkan Elemen Secara Terurut
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

void insertSorted_2311104010(List &L, int value)
{
    Node *newNode = new Node;
    newNode->data = value;

    if (L.head == NULL || L.head->data >= value)
    {
        newNode->next = L.head;
        L.head = newNode;
    }
    else
    {
        Node *current = L.head;
        while (current->next != NULL && current->next->data < value)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayList_2311104010(List L)
{
    Node *current = L.head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    List L;
    L.head = NULL;
    int value;

    // Memasukkan 4 elemen ke dalam list
    for (int i = 0; i < 4; i++)
    {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> value;
        insertLast_2311104010(L, value);
    }

    cout << "Masukkan elemen baru yang ingin ditambahkan: ";
    cin >> value;
    insertSorted_2311104010(L, value);

    cout << "List setelah elemen baru dimasukkan: ";
    displayList_2311104010(L);

    return 0;
}
