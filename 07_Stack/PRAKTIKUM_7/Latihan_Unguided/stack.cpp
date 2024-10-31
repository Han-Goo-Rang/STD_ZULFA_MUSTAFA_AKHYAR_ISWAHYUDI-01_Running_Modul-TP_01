#include <iostream>
#include "stack.h"
using namespace std;

void createStack(stack &S)
{
    S.Top = 0;
}
bool isEmpty(stack S)
{
    return S.Top == 0;
}
bool isFull(stack S)
{
    return S.Top == 15;
}
void push(stack &S, infotype x)
{
    if (!isFull(S))
    {
        S.Top += 1;
        S.info[S.Top - 1] = x;
    }
    else
    {
        cout << "Stack penuh!" << endl;
    }
}
infotype pop(stack &S)
{
    if (!isEmpty(S))
    {
        infotype x = S.info[S.Top - 1];
        S.Top -= 1;
        return x;
    }
    else
    {
        cout << "Stack kosong!" << endl;
        return '\0';
    }
}
void printInfo(stack S)
{
    if (!isEmpty(S))
    {
        for (int i = S.Top - 1; i >= 0; i--)
        {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Stack kosong!" << endl;
    }
}
