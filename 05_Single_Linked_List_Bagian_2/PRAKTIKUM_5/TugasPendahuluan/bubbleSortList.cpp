// Mengurutkan List Menggunakan Bubble Sort
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

void bubbleSort_2311104010(List &L)
{
    if (L.head == NULL)
        return;

    bool swapped;
    Node *current;
    Node *last = NULL;

    do
    {
        swapped = false;
        current = L.head;

        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
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

    // Memasukkan 5 elemen ke dalam list
    for (int i = 0; i < 5; i++)
    {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> value;
        insertLast_2311104010(L, value);
    }

    // Mengurutkan list dengan bubble sort
    bubbleSort_2311104010(L);

    // Menampilkan list yang sudah terurut
    cout << "List setelah diurutkan: ";
    displayList_2311104010(L);

    return 0;
}
