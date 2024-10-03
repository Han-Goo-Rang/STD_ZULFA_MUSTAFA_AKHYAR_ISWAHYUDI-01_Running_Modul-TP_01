#include <iostream>
using namespace std;

int main()
{
    int f, g, h;

    cout << "Beri ukuran untuk dimensi pertama: ";
    cin >> f;
    cout << "Beri ukuran untuk dimensi kedua: ";
    cin >> g;
    cout << "Beri ukuran untuk dimensi ketiga: ";
    cin >> h;

    int ***arraytigad = new int **[f];
    for (int i = 0; i < f; i++)
    {
        arraytigad[i] = new int *[g];
        for (int j = 0; j < g; j++)
        {
            arraytigad[i][j] = new int[h];
        }
    }

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < g; j++)
        {
            for (int k = 0; k < h; k++)
            {
                arraytigad[i][j][k] = i + j + k;
            }
        }
    }

    cout << "Isi array-nya:";
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < g; j++)
        {
            for (int k = 0; k < h; k++)
            {
                cout << "arraytigad[" << i << "][" << j << "][" << k << "] = " << arraytigad[i][j][k] << endl;
            }
        }
    }

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < g; j++)
        {
            delete[] arraytigad[i][j];
        }
        delete[] arraytigad[i];
    }
    delete[] arraytigad;

    return 0;
}
