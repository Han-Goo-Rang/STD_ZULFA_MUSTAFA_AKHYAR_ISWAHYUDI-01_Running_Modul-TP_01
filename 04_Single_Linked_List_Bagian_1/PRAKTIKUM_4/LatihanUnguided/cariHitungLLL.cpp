#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void depan(Node *&head, int nilai)
{
    Node *newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

void belakang(Node *&head, int nilai)
{
    Node *newNode = new Node();
    newNode->data = nilai;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool cariNode(Node *head, int nilai)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == nilai)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int panjangList(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void ngasihLiatList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = nullptr;
    depan(head, 10);
    belakang(head, 20);
    depan(head, 5);
    belakang(head, 30);
    depan(head, 40);
    depan(head, 50);
    belakang(head, 60);
    belakang(head, 70);

    if (cariNode(head, 60))
    {
        cout << "Node = 60 ada." << endl;
    }
    else
    {
        cout << "Node = 60 gada." << endl;
    }
    cout << "Panjang total LL-nya: " << panjangList(head) << endl;

    return 0;
}
