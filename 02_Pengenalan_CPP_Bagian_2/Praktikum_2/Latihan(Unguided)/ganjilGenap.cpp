#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a;
    cout << "Masukin angka : ";
    cin >> a;

    vector<int> array(a);
    cout << "Ayo masukin " << a << " buah angkanya : ";
    for (int g = 0; g < a; g++)
    {
        cin >> array[g];
    }

    vector<int> ganjil, genap;
    for (int g = 0; g < a; g++)
    {
        if (array[g] % 2 == 0)
            genap.push_back(array[g]);
        else
            ganjil.push_back(array[g]);
    }

    cout << "untuk array-nya : ";
    for (int g = 0; g < a; g++)
    {
        cout << array[g] << " ";
    }
    cout << endl;

    cout << "angka genap : ";
    for (int g = 0; g < genap.size(); g++)
    {
        cout << genap[g] << " ";
    }

    cout << endl;

    cout << "angka ganjil : ";
    for (int g = 0; g < ganjil.size(); g++)
    {
        cout << ganjil[g] << " ";
    }
    cout << endl;
    return 0;
}