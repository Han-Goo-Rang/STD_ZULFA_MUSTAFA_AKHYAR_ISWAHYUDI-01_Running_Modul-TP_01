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
void hapusNode(Node *&head, int nilai)
{
    if (head == nullptr)
        return;

    if (head->data == nilai)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != nilai)
    {
        temp = temp->next;
    }

    if (temp->next != nullptr)
    {
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
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
    hapusNode(head, 50);
    ngasihLiatList(head);

    return 0;
}
