#include <iostream>
#include "stack.h"
using namespace std;

void fillStack(stack &S, const string &data)
{
    for (char ch : data)
    {
        push(S, ch);
    }
}

void popUntil(stack &S, int n)
{
    for (int i = 0; i < n; i++)
    {
        pop(S);
    }
}

int main()
{
    stack S;
    createStack(S);

    int lastDigitNIM;
    string initialData, finalData;

    switch (lastDigitNIM % 4)
    {
    case 0:
        initialData = "IFLABJAYA";
        finalData = "JAYA";
        break;
    case 1:
        initialData = "HALOBANDUNG";
        finalData = "BANDUNG";
        break;
    case 2:
        initialData = "PERCAYADIRI";
        finalData = "DIRI";
        break;
    case 3:
        initialData = "STRUKTURDATA";
        finalData = "DATA";
        break;
    }

    fillStack(S, initialData);
    cout << "Isi stack awal: ";
    printInfo(S);

    popUntil(S, initialData.size() - finalData.size());
    cout << "Isi stack sesudah pop: ";
    printInfo(S);

    return 0;
}
