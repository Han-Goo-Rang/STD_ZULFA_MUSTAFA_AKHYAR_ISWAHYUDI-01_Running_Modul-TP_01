#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int bil;
    cout << "Masukin bilangannya : ";
    cin >> bil;

    vector<int> array(bil);

    cout << "masukkan sebanyak " << bil << " buah angka ";
    for (int o = 0; o < bil; o++)
    {
        cin >> array[o];
    }

    int maximal = *max_element(array.begin(), array.end());
    int minimum = *min_element(array.begin(), array.end());
    double roto2 = accumulate(array.begin(), array.end(), 0.0) / bil;

    cout << "nilai maksimalnya itu : " << maximal << endl;
    cout << "nilai minimalnya itu : " << minimum << endl;
    cout << "kalo di roto-roto : " << roto2 << endl;
    return 0;
}